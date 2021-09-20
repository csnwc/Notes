#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   FILE *fp;
   if((fp = fopen("file.txt", "w")) == NULL){
      printf("Cannot open file\n");
      exit(EXIT_FAILURE);
   }
   fprintf(fp, "Hello World\n");
   fclose(fp);
   return 0;
}
