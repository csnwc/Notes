/*Author: Gene Hackman kq18265
 *NB - Original assignment specified using '.' to indicate
 route through maze.  This has been changed to arrows 
 following guidance given by Dr Campbell in lab.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXROWS 20 
#define MAXCOLS 20 

enum cell_contents {wall, empty, breadcrumb};
typedef enum cell_contents contents;

enum gap_presence {entry_present=100, exit_present, no_exit, no_entry};
typedef enum gap_presence gap;

enum route {blocked, clear};
typedef enum route route;

int read_maze (int x, FILE *fp, char maze_grid[][MAXCOLS]); 
int find_entry_row (int x, char maze_grid[][MAXCOLS]);
int find_entry_col (int y, char maze_grid[][MAXCOLS]);
gap determine_entry_cell(int x, int y, int start_cell[]); 
gap find_exit_row (int x, int y, char maze_grid[][MAXCOLS]);
void print_maze (int x, int y, char maze_grid[][MAXCOLS]);
route explore (int x, int y, char maze_grid[][MAXCOLS]);
route backtrack (int x, int y, char mz[][MAXCOLS]);
contents determine_wall(char c); 

int main (int argc, char *argv[]) 
{

   FILE *fp;
   int x, y; /*Maze co-ordinates*/
   int start_cell[] = {0, 0};
   char maze_grid[MAXROWS][MAXCOLS];
   int entry_row;
   int entry_col;

   if (argc != 2) {
      fprintf(stderr, "Error: Maze template file must be passed as argument.\n");
      exit(2);
   }

   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      fprintf(stderr, "Maze template file '%s' not found.\n", argv[1]);
      exit(3);
   }
   
   /*Reads in width and height of grid as defined in file's first row*/
   fscanf(fp, "%d %d", &x, &y);
   
   if (read_maze(x, fp, maze_grid) != (x*y)) {
      fprintf(stderr, "Error present in maze template file '%s'.\n", argv[1]);
      fprintf(stderr, "Potential errors might include presence of characters other than\n");
      fprintf(stderr, "'#' or ' '; or grid dimensions incorrect.\n");
      exit(4);
   }

   fclose(fp);
   
   entry_row = find_entry_row(x, maze_grid);
   entry_col = find_entry_col(y, maze_grid);
   if (determine_entry_cell(entry_row, entry_col, start_cell)==no_entry) {
     fprintf(stderr, "Error present in maze template file '%s'.\n", argv[1]);
      fprintf(stderr, "Maze has no entry!\n");
      exit(5);
   }
   
   if (find_exit_row(x, y, maze_grid) == no_exit) {
      fprintf(stderr, "Error present in maze template file '%s'.\n", argv[1]);
      fprintf(stderr, "Maze has no exit!\n");
      exit(6);
   }
   
   printf("\nHere is the maze, is escape possible?!\n");
   printf("Start (s) and exit (e) are marked.\n\n");
   print_maze(x, y, maze_grid);

   if(explore(start_cell[0], start_cell[1], maze_grid)==1) {
      printf("\nEscape is possible!\n");
      printf("\nFollow the arrows:\n");
      printf("(Colons mark if your guide had to double back!)\n\n");
      print_maze(x, y, maze_grid);
      printf("\n");
      return 0;
   } else if (explore(start_cell[0], start_cell[1], maze_grid)==0){
      printf("\nNo route through the maze exists!\n\n");
      print_maze(x, y, maze_grid);
   }

   return 1;
}


int read_maze (int x, FILE *fp, char maze_grid[][MAXCOLS]) 
{

   int i = 0, j = 0, total = 0, c;
   
   while((c = getc(fp)) != EOF) 
   {
      if (c == '#' ||c == ' ') {
         maze_grid[i][j] = c;
         j++;
         total++;
      }
      if (j>=x) {
         j = 0;
         i++;
      }
   }
  
   return total;
}


int find_entry_row (int x, char maze_grid[][MAXCOLS])
{
   
   int i;

   for (i=0;i<x;i++) {
      if (maze_grid[i][0] == ' ') {
         maze_grid[i][0] = 's';
         return i;
      }
   }
   
   return no_entry;
}


int find_entry_col (int y, char maze_grid[][MAXCOLS])
{
   
   int i;

   for (i=0;i<y;i++) {
      if (maze_grid[0][i] == ' ') {
         maze_grid[0][i] = 's';
         return i;
      }
   }
   
   return no_entry;
}


gap determine_entry_cell(int x, int y, int start_cell[])
{
   
   if ((x == no_entry) && (y == no_entry)) {
      return no_entry;
   }

   if (x < y) {
      start_cell[0] = x;
      start_cell[1] = 0;
   } else {
      start_cell[0] = 0;
      start_cell[1] = y;
   }

   return entry_present;
}


gap find_exit_row (int x, int y, char maze_grid[][MAXCOLS])
{

   int i; 
   gap exit_status = no_exit;

   for (i = 0; i < x; i++) {
      if (maze_grid[i][y-1] == ' ') {
         maze_grid[i][y-1] = 'e';
         exit_status = exit_present;
      }
   }

   return exit_status;
}


void print_maze (int x, int y, char maze_grid[][MAXCOLS]) 
{
   int i, j;
   for (i = 0; i < x; i++) {
      for (j = 0; j < y; j++) {
         printf("%c", maze_grid[i][j]);
      }
      printf("\n");
   }
}


route explore (int x, int y, char mz[][MAXCOLS])
{
   if (mz[x][y] == 'e') {
      return clear;
   }

   /* Explore up */
   if (determine_wall(mz[x-1][y]) == empty) {
      mz[x][y] = '^';
      return explore (x-1, y, mz);
   }

   /* Explore right */
   if (determine_wall(mz[x][y+1]) == empty) {
      mz[x][y] = '>';
      return explore (x, y+1, mz);
   }
   
   /* Explore left*/
   if (determine_wall(mz[x][y-1]) == empty) {
      mz[x][y] = '<';
      return explore (x, y-1, mz);
   }
   
   /* Explore down*/
   if (determine_wall(mz[x+1][y]) == empty) {
      mz[x][y] = 'v';
      return explore (x+1, y, mz);
   }

   return backtrack(x, y, mz);

   return blocked;
}

route backtrack (int x, int y, char mz[][MAXCOLS])
{

   if (mz[x][y] == 'e') {
      return clear;
   }

   mz[x][y] = ':';
   
   /* Explore up */
   if (determine_wall(mz[x-1][y]) == breadcrumb) {
      return explore (x-1, y, mz);
   }
   /* Explore right */
   if (determine_wall(mz[x][y+1]) == breadcrumb) {
      return explore (x, y+1, mz);
   }
   
   /* Explore left*/
   if (determine_wall(mz[x][y-1]) == breadcrumb) {
      return explore (x, y-1, mz);
   }
   
   /* Explore down*/
   if (determine_wall(mz[x+1][y]) == breadcrumb) {
      return explore (x+1, y, mz);
   }
   
   return blocked;
}


contents determine_wall(char c) 
{

   switch (c) {
      case '^':
      case '>':
      case '<':
      case 'v':
         return breadcrumb;
         break;
      case ' ':
      case 'e':
         return empty;
         break;
      default:
         return wall;
   }
}

