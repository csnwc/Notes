#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   printf("Randomly distributed integers are printed.\n"
           "How many do you want to see?  ");
   int n;
   if(scanf("%i", &n) == 1){
      for (int i = 0; i < n; ++i) {
         if (i % 4 == 0){
            printf("\n");
         }
         printf("%12i", rand());
      }
      printf("\n");
      return 0;
   }
   return 1;
}
