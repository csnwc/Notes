/* Precision Demo */

#include <stdio.h>
#include <math.h>

int main(void)
{
   int i;
   double x, y;
   printf("Enter a Number : ");
   scanf("%lf", &x);
   y = x;
   for(i=0; i<100000; i++){
      y = pow(y, 80.0);
      y = pow(y, 1.0/80.0);
   }
   printf("%.10f %.10f\n", x, y);
   return 0;
}
