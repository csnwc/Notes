/* Compute the Area of a Sphere
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
   double a = 4.0 / 3.0 * PI * pow(r, (double) 3);
   printf("Area of your ball = %f\n", a);
   printf("Area of your ball = %.2f\n", a);
   printf("Area of your ball = %d\n", (int)a);
   printf("Area of your ball = %.0f\n", round(a));
   return 0;
}
