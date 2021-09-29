#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MAX 5

// Pass array, AND number of elements
void set_array(int a[MAX], unsigned int len, int n);

int main(void)
{
   int x[MAX] = {2, 3, 3, 3, 3};
   set_array(x, 5, 3); assert(x[0] == 3);
   x[0] = 5; x[1] = 5; x[2] = 5; x[3] = 5; x[4] = 5;
   set_array(x, 5, 4); assert(x[2] == 4);
   set_array(x, 1, 0); assert(x[0] == 0);
   x[0] = 1; x[1] = 2; x[2] = 3;
   set_array(x, 3, 2);
   assert(x[2] == 2); assert(x[3] == 4);
}

// Set all values of array (size len) to n
void set_array(int a[MAX], unsigned int len, int n)
{
   if(len == 0){
      return;
   }
   for(unsigned int i=0; i<len; i++){
     a[i] = n;
   }
}
