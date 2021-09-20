#include <stdio.h>
#include <stdlib.h>

struct examp {
   int h[100];
   double k;
   char c;
};
typedef struct examp examp;

int main(void)
{

   FILE *fp;
   examp e;
   if((fp = fopen("doof", "rb")) == NULL){
      printf("Cannot read file\n");
      exit(EXIT_FAILURE);
   }
   /* Should really check return value from fread */
   fread(&e, sizeof(struct examp), 1, fp);
   printf("k = %f\n", e.k);
   fclose(fp);

/*
   e.k += 0.1;
*/

   if((fp = fopen("doof", "wb")) == NULL){
      printf("Cannot write file\n");
      exit(EXIT_FAILURE);
   }
   /* Should really check return value from fwrite */
   fwrite(&e, sizeof(struct examp), 1, fp);
   fclose(fp);
   return 0;
}
