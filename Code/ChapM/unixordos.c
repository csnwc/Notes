#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGSTR 10000

int main(int argc, char* argv[])
{
   if(argc != 2){
      fprintf(stderr, "Usage : %s <file>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   FILE* fpin = fopen(argv[1], "rb");
   if(!fpin){
      fprintf(stderr, "Cannot read %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   char str[BIGSTR];
   if(fgets(str, BIGSTR, fpin)==NULL){
      fprintf(stderr, "Cannot read %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   int n = strlen(str); 
   if(n > 1){
      if((str[n-1] == '\n') && (str[n-2] == '\r')){
         printf("Looks like a DOS file?\n");
      }
      else{
         printf("Looks like a Unix file?\n");
      }
   }
   fclose(fpin);
   return EXIT_SUCCESS;
}
