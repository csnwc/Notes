/* Try to write mult(a,b) without using
   any maths cleverer than addition.     */

#include <stdio.h>
#include <assert.h>

int mult( int a,  int b);
void test(void);

int main(void)
{
   test();

   return 0;
}

int mult( int a,  int b)
{

// To be completed

}

void test(void)
{
   assert(mult(5,3) == 15);
   assert(mult(3,5) == 15);
   assert(mult(0,3) == 0);
   assert(mult(3,0) == 0);
   assert(mult(1,8) == 8);
   assert(mult(8,1) == 8);
}
