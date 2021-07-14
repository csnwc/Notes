#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MAX 5
// Pass array, AND number of elements
int set_mean(int a[], unsigned int num);

int main(void)
{
   int x[MAX], m;
   x[0] = 2; x[1] = 3; x[2] = 3; x[3] = 3; x[4] = 3;
   m  = set_mean(x, 5); assert(m==3); assert(x[0] == m);
   x[0] = 5; x[1] = 5; x[2] = 5; x[3] = 5; x[4] = 5;
   m  = set_mean(x, 5); assert(m==5); assert(x[2] == m);
   assert(set_mean(x, 1)==5);
   x[0] = 1; x[1] = 2; x[2] = 3;
   assert(set_mean(x, 3)==2);
   m  = set_mean(x, 3); assert(m==2); assert(x[1] == m);
   // Should also check for num !=  0 ??
}

// Mean rounded later from doubles - each element of array set to mean
int set_mean(int a[], unsigned int num)
{
   double tot = 0;
   for(unsigned int i=0; i<num; i++){
     tot += (double)a[i];
   }
   int mn = round(tot / (double) num);
   for(unsigned int i=0; i<num; i++){
     a[i] = mn;
   }
   return mn;
}
