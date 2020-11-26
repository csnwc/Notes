/**********************************/
/*         MAZE SOLVER            */
/**********************************/
/* A program to find a solution   */
/* to a maze (if it exists).      */
/* Can handle branches/dead ends. */
/**********************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum bool {false, true};
typedef enum bool bool;

#define COLS 20
#define ROWS 20
#define OPEN ' '
#define WALL '#'
#define PATH '+'
#define NORTH x-1, y
#define SOUTH x+1, y
#define EAST x, y+1
#define WEST x, y-1

bool explore(char mz[][COLS], int x, int y, int rows, int cols);
bool move(char mz[][COLS], int x, int y, int rows, int cols, char seeking);
void find_entrance(char mz[][COLS], int entrance[], int rows);
bool is_exit(int x, int y, int rows, int cols);
char read(char mz[][COLS], int x, int y, int rows, int cols);
void print_directions(char mz[][COLS], int x, int y, int rows, int cols);
int* filetodimensions(FILE *fp, int *dim, int *rows, int *cols);
void filetoarray(FILE *fp, char array[][COLS], int cols); 
FILE *gfopen(char filename[]);
void print_maze(char array[][COLS], int rows, int cols);

int main(int argc, char **argv)
{
   /* read file and copy maze to array */
   FILE *fp = gfopen(argv[1]); 
   char mz[ROWS][COLS];
   int dimension[] = {0, 0};
   int entrance[] = {0, 0};
   int rows, cols; 
   filetodimensions(fp, dimension, &rows, &cols);  
   filetoarray(fp, mz, cols);
   (void) argc; 

   /* find entrance */
   find_entrance(mz, entrance, rows);

   /* explore maze */
   if (explore(mz, entrance[0], entrance[1], rows, cols)){
      print_maze(mz, rows, cols);
      print_directions(mz, entrance[0], entrance[1], rows, cols);
      return 0;
   } 

   /* no solution found */
   fprintf(stderr, "\nNo solution found\n");
   return 1;
}

/**********************************/
/*          MAZE  FUNCS           */
/**********************************/

bool explore(char mz[][COLS], int x, int y, int rows, int cols)
{
   /* mark current location as solution path */
   mz[x][y] = PATH;

   if (is_exit(x, y, rows, cols)){
      printf("\nSOLUTION FOUND!\n");
      return true; 
   } 
   /* try all directions */
   if (move(mz, x, y, rows, cols, OPEN)){
      return true;
   }
   /* dead end: mark current location as wall*/
   mz[x][y] = WALL;

   /* dead end: backtrack along solution path */
   if (move(mz, x, y, rows, cols, PATH)){
      return true;
   }

   /* failed to find exit */
   return false;
}

bool move (char mz[][COLS], int x, int y, int rows, int cols, char seeking)
{
   if (read(mz, EAST, rows, cols) == seeking){
      explore(mz, EAST, rows, cols);
      return true;
   }
   if (read(mz, WEST, rows, cols) == seeking){
      explore(mz, WEST, rows, cols);
      return true;
   }
   if (read(mz, NORTH, rows, cols) == seeking){
      explore(mz, NORTH, rows, cols);
      return true;
   }
   if (read(mz, SOUTH, rows, cols) == seeking){
      explore(mz, SOUTH, rows, cols);
      return true;
   }
   /* no move possible with desired marker */
   return false;
}

char read(char mz[][COLS], int x, int y, int rows, int cols)
{
   if (x >= rows || x < 0){
      return WALL;
   }
   if (y >= cols || y < 0){
      return WALL;
   }
   return mz[x][y]; 
}

void find_entrance(char mz[][COLS], int entrance[], int rows)
{
   int i;
   /* scan first column and top row for entrance */
   for (i = 0; i < rows; i++){
      if (mz[i][0] == OPEN){
            entrance[0] = i;
            entrance[1] = 0;
      } else if (mz[0][i] == OPEN){
            entrance[0] = 0;
            entrance[1] = i;
     }
   }
}

bool is_exit(int x, int y, int rows, int cols)
{
   if (x == (rows-1) || y == (cols-1)){
      return true;
   }
   return false;
}

void print_directions(char mz[][COLS], int x, int y, int rows, int cols)
{
   while (!is_exit(x, y, rows, cols)){
      mz[x][y] = WALL;
      if (read(mz, EAST, rows, cols) == PATH){ 
         y++;
         printf("\nGo EAST.");
      } else if (read(mz, WEST, rows, cols) == PATH){
         y--;
         printf("\nGo WEST.");
      } else if (read(mz, NORTH, rows, cols) == PATH){
         x--;
         printf("\nGo NORTH.");
      } else if (read(mz, SOUTH, rows, cols) == PATH){
         x++;
         printf("\nGo SOUTH.");
      }
   }
   printf("\n");
}

/**********************************/
/*          HELPER FUNCS          */
/**********************************/

int* filetodimensions(FILE *fp, int *dim, int *rows, int *cols)
{
   /* store 2 integers */
   if (fscanf(fp, "%d%d", &dim[0], &dim[1]) < 2 ){
      fprintf(stderr, "\nError reading dimensions\n");
      exit(1);
   } 
   *rows = dim[0];
   *cols = dim[1];
   return dim;
}

void filetoarray(FILE *fp, char array[][COLS], int cols)
{
   char c;  
   int i = 0, j = 0, cnt = 0; 
   /* only store maze characters */
   while ((c = fgetc(fp)) != EOF) {
      if ((c == WALL) || (c == OPEN)){
         array[i][j++] = c;
         cnt++; 
         if ((j) == cols){
            i++; 
            j = 0; 
         }
      }
   }
   /* confirm correct number of elements stored */
   if (!(cnt == cols * cols)){
      fprintf(stderr, "\nError storing maze array\n");
      exit(1);
   }
}

FILE *gfopen(char filename[])
{
   FILE *fp;
   /* sets a pointer to a file */
   if ((fp = fopen(filename, "r")) == NULL){
      fprintf(stderr, "\nError while opening file\n");
      exit(1);
   }
   return fp; 
}

void print_maze(char array[][COLS], int rows, int cols)
{
   int i, j;
   for (i = 0; i < rows; i++){
      for (j = 0; j < cols; j++){
         printf("%c", array[i][j]);
         if ((j+1) == cols){
            printf("\n");
         }
      }
   }
}
