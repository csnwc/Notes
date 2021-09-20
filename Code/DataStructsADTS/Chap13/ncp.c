#include <stdio.h>
#include <stdlib.h>
#define MAXFILENAME 128

int main(void)
{
   FILE *ifp, *ofp;
   char inpname[MAXFILENAME];
   char oupname[MAXFILENAME];
   int i;
   printf("Enter two filenames : ");
   if(scanf("%s %s", inpname, oupname) != 2){
      printf("Failed to scan two filenames.");
      exit(EXIT_FAILURE);
   }
   ifp = fopen(inpname, "rb");
   ofp = fopen(oupname, "wb");
   if(ifp == NULL || ofp == NULL){
      printf("Failed to open two filenames.");
      exit(EXIT_FAILURE);
   }
   while((i = fgetc(ifp)) != EOF){
      fputc(i, ofp);
   };
   fclose(ifp);
   fclose(ofp);
   return 0;
}
