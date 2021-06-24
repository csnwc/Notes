#include <stdio.h>
#include <assert.h>

int fact(int a);

int main(void)
{
   assert(fact(4) == 24);
   assert(fact(1) == 1);
   assert(fact(0) == 1);
   assert(fact(10) == 3628800);
   return(0);

}

int fact(int a)
{

   if(a > 0)
      return ( a * fact(a - 1) );
   else
      return 1;

}
