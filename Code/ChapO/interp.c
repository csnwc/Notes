#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define NMBRS 1000000

int interp(int k, const int* a, int l, int r);

int main(void)
{
   int a[NMBRS];
   srand(time(NULL));

   // Put even numbers into array
   for(int i=0; i<NMBRS; i++){
      a[i] = 2*i;
   }

   // Do many searches for a random number
   for(int i=0; i<10*NMBRS; i++){
      int n = rand()%NMBRS;
      if((n%2) == 0){
         assert(interp(n, a, 0, NMBRS-1) == n/2);
      }
      else{ // No odd numbers in this list
         assert(interp(n, a, 0, NMBRS-1) < 0);
      }
   }
   return 0;
}

int interp(int k, const int* a, int l, int r)
{

   int m;
   double md;

   while(l <= r){
      md = ((double)(k-a[l])/
            (double)(a[r]-a[l])*
            (double)(r-l)
           )
           +(double)(l);
      m  = 0.5 + md;
      if((m > r) || (m < l)){
         return -1;
      }
      if(k == a[m])
         return m;
      else{
         if (k > a[m]){
            l = m + 1;
         }
         else{
            r = m- 1;
         }
      }
   }
   return -1;
}
