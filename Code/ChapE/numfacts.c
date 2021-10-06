#include <stdio.h>

int numfactors(int f);

int main(void)
{

   int n = 12;
   printf("Number of factors in %i is %i\n", \
          n, numfactors(n));
   return 0;
}

int numfactors(int k)
{

   int count = 0;

   for(int i=1; i<=k; i++){
      if( (k%i)==0) {
         count++;
      }
   }
   return count;
}
