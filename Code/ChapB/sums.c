// Sums are computed.
#include <stdio.h>

int main(void)
{

   int cnt = 0;
   float sum = 0.0, x;
   printf("Input some numbers: ");
   while (scanf("%f", &x) == 1) {
      cnt = cnt + 1;
      sum = sum + x;
   }

   printf("\n%s%5d\n%s%5f\n\n",
           "Count:", cnt, "Sum: ", sum);
   return 0;
}
