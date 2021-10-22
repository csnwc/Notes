#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define NMBRS 1000000

int bin_it(int k, const int* a, int l, int r);

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
         assert(bin_it(n, a, 0, NMBRS-1) == n/2);
      }
      else{ // No odd numbers in this list
         assert(bin_it(n, a, 0, NMBRS-1) < 0);
      }
   }
   return 0;
}

int bin_rec(int k, const int* a, int l, int r)
{
   if(l > r) return -1;
   int m = (l+r)/2;
   if(k == a[m]){
      return m;
   }
   else{
      if (k > a[m]){
         return bin_rec(k, a, m+1, r);
      }
      else{
         return bin_rec(k, a, l, m-1);
      }
   }
}
