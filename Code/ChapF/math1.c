/* Compute the Volume of a Sphere
   to the nearest integer       */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
   double r;
   printf("Enter a radius : ");
   scanf("%lf", &r);
   // Make sure radius is positive
   r = fabs(r);
   double v = 4.0 / 3.0 * PI * pow(r, (double) 3);
   printf("Volume of your ball = %f\n", v);
   printf("Volume of your ball = %.2f\n", v);
   printf("Volume of your ball = %i\n", (int)v);
   printf("Volume of your ball = %.0f\n", v);
   printf("Volume of your ball = %f\n", round(v));
   return 0;
}
