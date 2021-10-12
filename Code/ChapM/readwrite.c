#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIGSTR 500
#define FNAME "helloworld.txt"

int main(void)
{
   FILE* fp = fopen("helloworld.txt", "w");
   if(fp == NULL){
      fprintf(stderr, "Cannot open file %s ?\n", FNAME);
      exit(EXIT_FAILURE);
   }
   fprintf(fp, "Hello World!\n");
   fclose(fp);

   fp = fopen("helloworld.txt", "r");
   if(fp == NULL){
      fprintf(stderr, "Cannot read file %s ?\n", FNAME);
      exit(EXIT_FAILURE);
   }
   char str[BIGSTR];
   if(fgets(str, BIGSTR, fp) == NULL){
      fprintf(stderr, "Cannot read 1st line of %s ?\n", FNAME);
      exit(EXIT_FAILURE);
   }
   fclose(fp);
   // Newline is read too
   if(strcmp(str,  "Hello World!\n")){
      fprintf(stderr, "1st line of %s not correct?\n", FNAME);
      exit(EXIT_FAILURE);
   }
   return EXIT_SUCCESS;
}
