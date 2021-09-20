#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define NMBRS 1000000

int interp(int k, int *a, int l, int r);

int main(void)
{

   int i;
   int a[NMBRS];

   srand(time(NULL));
   for(i=0; i<NMBRS; i++){
      a[i] = 2*i;
   }
   for(i=0; i<10*NMBRS; i++){
      assert(interp(a[rand()%NMBRS], a, 0, NMBRS-1) >= 0);
   }

   return 0;

}

int interp(int k, int *a, int l, int r)
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
      if(k == a[m])
         return m;
      else{
         if (k > a[m])
            l = m + 1;
         else
            r = m- 1;
      }
   }
   return -1;
}
