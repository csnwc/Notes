#include <stdio.h>
#include <string.h>
typedef enum bool {false, true} bool;
#include "neillsimplescreen.h"

#define HEIGHT 10
#define WIDTH 10

#define START_X 1
#define START_Y 0

#define W '#'
#define H ' '
#define X 'X'
#define T 'T'

void print_maze(char mz[HEIGHT][WIDTH]);
bool explore(int x, int y, char mz[HEIGHT][WIDTH]);
bool valid(int x, int y, char mz[HEIGHT][WIDTH]);

int main(void)
{

   char maze[HEIGHT][WIDTH] = {{W,H,W,W,W,W,W,W,W,W},
                               {W,H,W,H,H,H,W,H,H,X},
                               {W,H,W,H,W,H,H,H,W,W},
                               {W,H,W,H,W,H,W,H,H,W},
                               {W,H,W,H,W,H,W,H,W,W},
                               {W,H,W,H,W,H,W,H,W,W},
                               {W,H,W,H,W,H,W,H,H,W},
                               {W,H,W,H,W,H,W,H,W,W},
                               {W,H,H,H,W,H,H,H,W,W},
                               {W,W,W,W,W,W,W,W,W,W}};

   print_maze(maze);
   if(explore(START_X, START_Y, maze)){
      print_maze(maze);
   }
   else{
      printf("No Valid Route ?\n");
   }
   return 0;
}

void print_maze(char mz[HEIGHT][WIDTH])
{
   int i, j;
   char c;
   printf("\n");
   for(j=0; j<HEIGHT; j++){
      for(i=0; i<WIDTH; i++){
         c = mz[j][i];
         switch(c){
            case H:
            case W:
               neillfgcol(green);
               break;
            case T:
               c = ' ';
               break;
            default:
               neillfgcol(red);
         }
         printf("%c", c);
      }
      printf("\n");
   }
   printf("\n");
   neillreset();
}

bool valid(int x, int y, char mz[HEIGHT][WIDTH])
{
   if(x>=WIDTH){
      return false;
   }
   if(x < 0){
      return false;
   }
   if(y>=HEIGHT){
      return false;
   }
   if(y < 0){
      return false;
   }
   if(mz[y][x] == X){
      return true;
   }
   if(mz[y][x] == H){
      return true;
   }
   return false;
}





















/* Don't show below here, stupid ! */
















bool explore(int x, int y, char mz[HEIGHT][WIDTH])
{
   /* Found the Exit */
   if(mz[y][x] == X){
      return true;
   }

   mz[y][x] = T;

   /* Go Right */
   if(valid(x+1, y, mz)){
      if(explore(x+1, y, mz)){
         mz[y][x] = '>';
         return true;
      }
   }


   /* Go Down */
   if(valid(x, y+1, mz)){
      if(explore(x, y+1, mz)){
         mz[y][x] = 'v';
         return true;
      }
   }

   /* Go Left */
   if(valid(x-1, y, mz)){
      if(explore(x-1, y, mz)){
         mz[y][x] = '<';
         return true;
      }
   }

   /* Go Up */
   if(valid(x, y-1, mz)){
      if(explore(x, y-1, mz)){
         mz[y][x] = '^';
         return true;
      }
   }


   return 0;

}
