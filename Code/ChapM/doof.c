// Some of the functionality of cp
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   if(argc != 3){
      fprintf(stderr, "Usage : %s <filein> <fileout>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   FILE* fpin = fopen(argv[1], "r");
   if(!fpin){
      fprintf(stderr, "Cannot read from %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   FILE* fpout = fopen(argv[2], "w");
   if(!fpout){
      fprintf(stderr, "Cannot write to %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   char c;
   while((c = fgetc(fpin)) != EOF){
      fputc(c, fpout);
   }
   fclose(fpin);
   fclose(fpout);
   return EXIT_SUCCESS;
}
