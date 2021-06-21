#include <stdio.h>

int main(void)
{
   // Compute the area of a rectangle
   int side1, side2, area;
   side1 = 7;
   side2 = 8;
   area = side1 * side2;
   
   printf("Length of side  1 = %d metres\n", side1);
   printf("Length of side  2 = %d metres\n", side2);
   printf("Area of rectangle = %d metres squared\n", area);
   return 0;
}
