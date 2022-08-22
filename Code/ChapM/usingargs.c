#include <stdio.h>

int main(int argc, char* argv[])
{

   printf("You typed %i arguments\n", argc);
   printf("The name of your executable is : %s\n", argv[0]);
   for(int i=1; i<argc; i++){
      printf("Argument %d is : %s\n", i, argv[i]);
   }

   return 0;
}
