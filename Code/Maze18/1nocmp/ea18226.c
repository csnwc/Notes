#include <stdio.h>
#define FIRSTROW 6

int explore(int y, int x, int ys, int xs, 
   char maze[ys][xs]);

int main(int argc, char *argv[])
{
   FILE *fp;
   int ys, xs;

   if ((fp = fopen(argv[1], "r")) == NULL) {
      printf("CANNOT OPEN FILE");
      return 1;
   }
   fscanf(fp, "%d %d", &ys, &xs);
   fseek(fp, FIRSTROW, SEEK_SET);

   char mztmp[ys][xs + 1], mz[ys][xs];
   int y, x;

   if (fread(mztmp, sizeof(char), ys * (xs + 1), fp)
          != ys * (xs + 1)) {
      printf("CANNOT READ FILE");
      return 1;
   }
   for (y = 0; y < ys; y++) {
      for (x = 0; x < xs; x++) {
         printf("%c", mztmp[y][x]);
         mz[y][x] = mztmp[y][x];
      }
      printf("\n");
   }
   printf("\n%d\n\n", explore(1, 0, ys, xs, mz));
   for (y = 0; y < ys; y++) {
      for (x = 0; x < xs; x++) {
         printf("%c", mz[y][x]);
      }
      printf("\n");
   }
   fclose(fp);
   return 0;
}

int explore(int y, int x, int ys, int xs, 
   char maze[ys][xs])
{
   if (maze[y][x] == ' ') {
      maze[y][x] = '.';
      if (y == (ys - 2) && x == (xs - 1)) {
         return 0;
      }
   } else {
      return 1;
   }

   if (explore(y - 1, x, ys, xs, maze)) {
      if (explore(y, x - 1, ys, xs, maze)) {
         if (explore(y, x + 1, ys, xs, maze)) {
            if (explore(y + 1, x, ys, xs, maze)) {
               return 1;
            }
         }
      }
   }

   return 0;
}
