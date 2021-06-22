#include <stdio.h>

int min(int a, int b);

int main(void)
{
   int   j, k, m;

   j = 6;
   k = 9;
   m = min(j, k);
   printf("Minimum of %d & %d = " \
          "%d\n", j, k, m);
   return 0;
}

int min(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}
