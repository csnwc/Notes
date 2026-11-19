#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#define MAX 30000000

bool isprime(int n);

int main(void)
{
   int cnt = 0;
   // Scheduler: dynamic, static etc.
   // Reduction: cnt is private otherwise
   // Not as simple as : #pragma omp parallel for
   #pragma omp parallel for schedule(guided) reduction(+:cnt)
   for(int i=0; i<MAX; i++){
      if(isprime(i)){
         cnt++;
      }
   }
   printf("%d Total\n", cnt);
   return 0;
}

bool isprime(int n)
{
   // Base cases
   if(n<=1) return false;
   if(n<=3) return true;
   if(n%2==0 || n%3==0) return false;
   for (int i=5; i*i<=n; i+= 6) {
      if (n%i==0 || n%(i+2) == 0){
         return false;
      }
   }
   return true; // No factors found, it is prime
}
