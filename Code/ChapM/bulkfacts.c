/* Compute some factorials and save them
   for another program to read back later. */
#include <stdio.h>
#include <stdlib.h>

#define FACTS 20

typedef unsigned long facttype;

int main(int argc, char* argv[])
{
   if(argc != 2){
      fprintf(stderr, "Usage : %s <fileout>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   FILE* fpout = fopen(argv[1], "wb");
   if(!fpout){
      fprintf(stderr, "Cannot write to %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   facttype facts[FACTS] = {1};
   for(facttype i=1; i<FACTS; i++){
      facts[i] = facts[i-1]*i;
   } 

   int n = fwrite(facts, sizeof(facttype), FACTS, fpout);
   if(n != FACTS){
      fprintf(stderr, "Cannot write to %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   fclose(fpout);
   return EXIT_SUCCESS;
}
