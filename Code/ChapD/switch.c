/* A Prime number can only be divided
   exactly by 1 and itself */

#include <stdio.h>

int main(void)
{

   int i, n;
   do{
      printf("\nEnter a number from 2 - 9 : ");
      n = scanf("%i", &i);
   }while( (n!=1) || (i<2) || (i>9) );
   switch(i){
      case 2:
      case 3:
      case 5:
      case 7:
         printf("That's a prime!\n");
         break;
      default:
         printf("That is not a prime!\n");
   }
   return 0;
}
