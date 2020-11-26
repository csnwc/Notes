#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <time.h>

#define FILE_NAME_MAX 128
#define VOID -1
#define ROWS 0
#define COLUMNS 1
#define RESET_COLOUR "\x1b[0m"
#define TRUE_PATH 1

struct Directions {
char *label;
int row_offset;
int col_offset;
int row_limit;
int col_limit;
};

const char* get_file_name(char file_name[FILE_NAME_MAX]);
int get_dimensions(int dimensions[2], FILE *fp);
int fill_array(char **array, int dimensions[2], FILE *fp);
int get_start(char **array, int dimensions[2], int entrance_coordinates[2]);
int explore(char **array, int dimensions[2], int row, int col, int entrance_coordinates[2]);
void delay(double delay_in_seconds);
int print_array(char **array, int dimensions[2]);

int main(void)
{
   FILE *fp;
   char **array, file_name[FILE_NAME_MAX];
   int dimensions[2] = {ROWS, COLUMNS}, entrance_coordinates[2];
   int i, success_check = 1;
/*Get file name and dimensions of maze*/
   fp = fopen(get_file_name(file_name), "r");
   if(fp == NULL){
      fprintf(stderr, "Failed to open text file containing the maze.\n");
      exit(1);
   }
   assert(get_dimensions(dimensions, fp)==EXIT_SUCCESS);
/*Allocate space for maze array based on dimensions*/
   array = malloc(dimensions[ROWS] * sizeof(char *));
	if(array == NULL){
	   fprintf(stderr, "Out of memory\n");
	   exit(1);
  	}
	for(i = 0; i < dimensions[ROWS]; i++){
	   array[i] = malloc(dimensions[COLUMNS] * sizeof(char));
	   if(array[i] == NULL){
	      fprintf(stderr, "Out of memory\n");
	      exit(1);
           }
	}
/*Fill the maze array, explore and print final version with steps taken*/
   assert(fill_array(array, dimensions, fp)==EXIT_SUCCESS);
   assert(get_start(array, dimensions, entrance_coordinates)==EXIT_SUCCESS);
   success_check = explore(array, dimensions, entrance_coordinates[ROWS], entrance_coordinates[COLUMNS], entrance_coordinates);
   delay(0.1);
   assert(print_array(array, dimensions)==EXIT_SUCCESS);
/*Clean things up*/
   for(i = 0; i < dimensions[ROWS]; i++){
      free(array[i]);
   }
   free(array);
   fclose(fp);
   if (success_check!=0){
      success_check=1;
      printf("There is no way out.\n");
   }
   printf("Return Success: %d.\n", success_check);
   return success_check;
}


/*Getting and printing the maze*/
const char* get_file_name(char file_name[FILE_NAME_MAX])
{
   printf("\nHello! Please type in the name (<128 characters)\nof the text file to be used for the maze:\n");
    if (scanf("%s", file_name) == 0){
      fprintf(stderr, "Failed to retrieve a file name.\n");
      exit(1);
   } 
   return file_name;
}


int get_dimensions(int dimensions[2], FILE *fp)
{
   char dimensions_input[10];
   if (fgets(dimensions_input, 10, fp) == NULL){
      fprintf(stderr, "Failed to retrieve dimensions.\n");
      return EXIT_FAILURE;
   }
   sscanf( dimensions_input, "%d %d", &dimensions[ROWS], &dimensions[COLUMNS]);
   if (dimensions[COLUMNS] <3 || dimensions[ROWS] <3 ){
      fprintf(stderr, "Dimensions too small or missing.\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}


int fill_array(char **array, int dimensions[2], FILE *fp)
{
   int i, r, c;
   for (i = 0; i<dimensions[ROWS]; i++){
      if (fgets(array[i], dimensions[COLUMNS]+2, fp) == NULL ){
         fprintf(stderr, "Failed to read the maze from the text file.\n");
         return EXIT_FAILURE;
      }
   }
   /*print out line by line*/
   delay(0.1);
   print_array(array, dimensions);
   /*......................*/
   for (r = 0 ; r < dimensions[ROWS] ; r++){
      for (c = 0 ; c < dimensions[COLUMNS] ; c++){
         if (array[r][c] != ' ' && array[r][c] != '#'){
            fprintf(stderr, "The file contains something other than the dimensions, hashes and spaces.\n");
            return EXIT_FAILURE;
         }
      }
   }
   if (array[0][0] == ' ' || array[0][0] == '#'){
      if (array[dimensions[ROWS]-1][dimensions[COLUMNS]-1] == ' ' || array[dimensions[ROWS]-1][dimensions[COLUMNS]-1] == '#'){
         return EXIT_SUCCESS;
      }
   }
   fprintf(stderr, "The array does not appear to have been read from the top-left to the bottom-right.\n");
   return EXIT_FAILURE;
}


int get_start(char **array, int dimensions[2], int entrance_coordinates[2])
{
   int r, c, first_row, first_col;
   for (r = dimensions[ROWS]-1 ; r > 0 ; r--){
      if (array[r][0] == ' '){
         first_row = r;
      }
   }
   for (c = dimensions[COLUMNS]-1; c > 0 ; c--){
      if (array[0][c] == ' '){
         first_col = c;
      }
   }
   if (first_row < first_col){
      entrance_coordinates[ROWS] = first_row;
      entrance_coordinates[COLUMNS] = 0;
   }
   if (first_col < first_row){
      entrance_coordinates[ROWS] = 0;
      entrance_coordinates[COLUMNS] = first_col;
   }
   if (first_row > -1 || first_row <dimensions[ROWS] || first_col > -1 || first_col < dimensions[COLUMNS] ){
      return EXIT_SUCCESS;
   }
   fprintf(stderr, "There appeared to be no entrance on the left or top sides\n");
   return EXIT_FAILURE;
}


int print_array(char **array, int dimensions[2])
{
   int r, c, print_check;
   for (r = 0 ; r < dimensions[ROWS] ; r++){
      for (c = 0 ; c < dimensions[COLUMNS] ; c++){
         if (array[r][c] == '#'){
            printf("\x1b[37;100m%c " RESET_COLOUR, array[r][c]);
            print_check++; 
         }  
         else{
            printf("\x1b[37;101m%c " RESET_COLOUR, array[r][c]);
            print_check++;
         }
      }
   printf("\n");
   }
   printf("\n");
   if (print_check != dimensions[ROWS] * dimensions[COLUMNS]){
      fprintf(stderr, "There has been an issue printing an element in the array\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}


/* Exploration */
int explore(char **array, int dimensions[2], int row, int col, int entrance_coordinates[2])
{
   int k, next_row =0, next_col =0, path_ahead = 0;
   static int steps_needed = 0;
   struct Directions direction_list[] =
      { /*label  | row+-|col+-|rowlimit           | collimit */
      {"right     ",  0,  1,   VOID,                dimensions[COLUMNS]-1  },
      {"up        ", -1,  0,   0,                   VOID    },
      {"left      ",  0, -1,   VOID,                0       },
      {"down      ",  1,  0,   dimensions[ROWS]-1,  VOID    },
   };
   /*Found the exit*/
   if (array[row][col] == ' ' && (row != entrance_coordinates[ROWS] || col != entrance_coordinates[COLUMNS])){
      if (col == dimensions[COLUMNS]-1 || row == dimensions[ROWS]-1 || col == 0 || row == 0){
         array[row][col] = '!';
         steps_needed++;
         return TRUE_PATH;
      }
   }
   /*Cycle through directions (recursive)*/
   for (k = 0; k<4; k++){
      if (row != direction_list[k].row_limit && col != direction_list[k].col_limit){
         next_row = row+direction_list[k].row_offset;
         next_col = col+direction_list[k].col_offset;
         if (array[next_row][next_col] == ' '){
            array[row][col] = '%';
            delay(0.1);
            print_array(array, dimensions);
            path_ahead = explore(array, dimensions, next_row, next_col, entrance_coordinates);
            if (path_ahead == TRUE_PATH){
               if (row!=entrance_coordinates[ROWS] || col!=entrance_coordinates[COLUMNS]){
               array[row][col] = '.';
               steps_needed++;
               return TRUE_PATH;
               } 
               /*Returned to the entrance*/
               if (row==entrance_coordinates[ROWS] && col==entrance_coordinates[COLUMNS]){
               array[row][col] = '?';
               steps_needed++;
               return 0;  
               }
            }
         }
      }
   }
   if (next_row < 0 || next_row > dimensions[ROWS]-1 || next_col <0 || next_col > dimensions[COLUMNS]-1){
      fprintf(stderr, "There has been an attempt to access outside the bounds of the maze array\n");
      exit(1);
   }
}

/*Other */
void delay(double delay_in_seconds)
{
   clock_t start_time = clock(); /*initialise variable start_time, of the type clock_t*/
   while (clock() < start_time + delay_in_seconds * CLOCKS_PER_SEC); /*CLOCKS_PER_SEC converts seconds to clock measure*/
   if (system("clear") == -1){
      printf("Error in clearing terminal.\n");
   }
}
