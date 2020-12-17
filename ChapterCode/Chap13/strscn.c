#include <stdio.h>
#include <stdlib.h>

#define STRLN 100

int main(void) 
{

   char str[STRLN];
   int i;
   fgets(str, STRLN, stdin);
   while(sscanf(str, "%d", &i) != 1){
      printf("Cannot scan string !\n");
      fgets(str, STRLN, stdin);
   }
   printf("The number was %d.", i);
   
   return 0;
}
