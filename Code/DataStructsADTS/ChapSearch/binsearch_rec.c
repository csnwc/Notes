#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define NMBRS 1000000

int bin_rec(int k, int *a, int l, int r);

int main(void)
{

   int i;
   int a[NMBRS];

   srand(time(NULL));
   for(i=0; i<NMBRS; i++){
      a[i] = 2*i;
   }
   for(i=0; i<10*NMBRS; i++){
      assert(bin_rec(a[rand()%NMBRS], a, 0, NMBRS-1) >= 0);
   }

   return 0;

}

int bin_rec(int k, int *a, int l, int r)
{

   int m;

   if(l > r) return -1;

   m = (l+r)/2;

   if(k == a[m])
      return m;
   else{
      if (k > a[m])
         return bin_rec(k, a, m+1, r);
      else
         return bin_rec(k, a, l, m-1);
   }
         
}
