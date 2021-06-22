#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int   i, n;
   printf("Randomly distributed integers are printed.\n"
           "How many do you want to see?  ");
   do{
      i = scanf("%d", &n);
   }while(i != 1);
   for (i = 0; i < n; ++i) {
      if (i % 4 == 0)
         printf("\n");
      printf("%12d", rand());
   }
   printf("\n");
   return 0;
}
