#include <stdio.h>
#include <string.h>

#define MAZE_Y 10
#define MAZE_X 10

#define START_X 1
#define START_Y 0

#define W '#'
#define H ' '
#define X '*'

int trawl(int x, int y, char maze[MAZE_Y][MAZE_X]);

int main(void)
{

   char maze[MAZE_Y][MAZE_X] = {{W,H,W,W,W,W,W,W,W,W},
                                {W,H,W,H,H,H,W,H,H,X},
                                {W,H,W,H,W,H,W,H,W,W},
                                {W,H,W,H,W,H,W,H,W,W},
                                {W,H,W,H,W,H,W,H,W,W},
                                {W,H,H,H,W,H,W,H,W,W},
                                {W,H,W,H,W,H,W,H,W,W},
                                {W,H,W,H,W,H,W,H,W,W},
                                {W,H,H,H,W,H,H,H,W,W},
                                {W,W,W,W,W,W,W,W,W,W}};

   if(trawl(START_X, START_Y, maze)){
      printf("(%d,%d)\nFound It !\n", START_X, START_Y);
   }
   else{
      printf("No Valid Route ?\n");
   }

   return 0;

}

int trawl(int x, int y, char mz[MAZE_Y][MAZE_X])
{


   char maze2[MAZE_Y][MAZE_X];

   if(mz[y][x] == X){
      return 1; /* Found the Exit */
   }

   mz[y][x] = W; /* Mark this as Visited */

   /* Go Down */
   if(y<(MAZE_Y-1) && mz[y+1][x] != W){
      memcpy(maze2, mz, MAZE_X*MAZE_Y);
      if(trawl(x, y+1, maze2)){
         printf("(%d,%d)\n", x, y+1);
         return 1;
      }
   }

   /* Go Right */
   if(x<(MAZE_X-1) && mz[y][x+1] != W){
      memcpy(maze2, mz, MAZE_X*MAZE_Y);
      if(trawl(x+1, y, maze2)){
         printf("(%d,%d)\n", x+1, y);
         return 1;
      }
   }

   /* Go Left */
   if(x>0 && mz[y][x-1] != W){
      memcpy(maze2, mz, MAZE_X*MAZE_Y);
      if(trawl(x-1, y, maze2)){
         printf("(%d,%d)\n", x-1, y);
         return 1;
      }
   }

   /* Go Up */
   if(y>0 && mz[y-1][x] != W){
      memcpy(maze2, mz, MAZE_X*MAZE_Y);
      if(trawl(x, y-1, maze2)){
         printf("(%d,%d)\n", x, y-1);
         return 1;
      }
   }

   return 0;

}
