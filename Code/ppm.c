#include <stdio.h>

#define WIDTH 256
#define HEIGHT 256

struct pixel{
	unsigned char r, g, b;
};


int main(void)
{

   struct pixel piccy[HEIGHT][WIDTH];
   FILE *fp;
   int y, x;

   for(y=0; y<HEIGHT; y++){
      for(x=0; x<WIDTH; x++){
         piccy[y][x].r = (unsigned char)x;
         piccy[y][x].g = (unsigned char)y;
         piccy[y][x].b = (unsigned char)((x+y*WIDTH)%256);
      }
   }

   if(!(fp = fopen("piccy.ppm", "w"))){
      fprintf(stderr, "Cannot write file ?\n");
      exit(2);
   }

   fprintf(fp, "P3\n");
   fprintf(fp, "# Neill made this\n");
   fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
   fprintf(fp, "255\n");

   for(y=0; y<HEIGHT; y++){
      for(x=0; x<WIDTH; x++){
         fprintf(fp, "%d %d %d ", piccy[y][x].r, piccy[y][x].g, piccy[y][x].b);
         if(x%16==0) fprintf(fp, "\n");
      }
   }

   fclose(fp);
   return 0;

}
