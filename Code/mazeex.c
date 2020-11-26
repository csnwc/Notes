#include <stdio.h>
#include <assert.h>

#define MAXX 20
#define MAXY 20

#define WALL '#'
#define EXIT 'X'

#define STRSIZE 200

int Explore(int x, int y, char maze[MAXY][MAXX]);

void ReadMaze(char maze[MAXY][MAXX], int *x, int *y);
void PrintMaze(char maze[MAXY][MAXX]);

int main(void)
{

   int xs, ys;
   char maze[MAXY][MAXX] = {{'\0'}};

   ReadMaze(maze, &xs, &ys);
   PrintMaze(maze);
   printf("There is %s valid route !\n", Explore(xs, ys, maze) ? "a" : "no");
   return 0;

}

void ReadMaze(char maze[MAXY][MAXX], int *x, int *y)
{

   FILE *fp;
   int j = 0;
   char fname[STRSIZE];

   printf("Enter the filename : ");
   assert(scanf("%s", fname) == 1);
   assert((fp = fopen(fname, "r")) != NULL);
   assert(fscanf(fp, "%d %d ", x, y) == 2);
   while(fgets(maze[j++], MAXX, fp) != NULL);
   fclose(fp);

}

void PrintMaze(char maze[MAXY][MAXX])
{

   int j;
   for(j=0; j<MAXY; j++)
      printf("%s", maze[j]);

}

int Explore(int x, int y, char mz[MAXY][MAXX])
{

   if(mz[y][x] == EXIT) return 1;

   mz[y][x] = WALL;

   if((y<(MAXY-1)) && (mz[y+1][x] != WALL) && Explore(x, y+1, mz))
      return 1;

   if((x<(MAXX-1)) && (mz[y][x+1] != WALL) && Explore(x+1, y, mz))
      return 1;

   if((x>0) && (mz[y][x-1] != WALL) && Explore(x-1, y, mz))
      return 1;

   if((y>0) && (mz[y-1][x] != WALL) && Explore(x, y-1, mz))
      return 1;

   return 0;

}
