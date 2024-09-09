/* Try to write power(a,b) to computer a^b
   without using any cleverer maths than
   multiplication : 
   Try (1) iterative then (2) recursive
   
*/

#include <stdio.h>

int power(unsigned int a, unsigned int b);

int main(void)
{

   int x = 2;
   int y = 16;

   printf("%d^%d = %d\n", x, y, power(x,y));

}

int power(unsigned int a, unsigned int b)
{
}
