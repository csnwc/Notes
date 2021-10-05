#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
   int   a = 3, b = 7;

   // 3 7 printed
   printf("%i %i\n", a, b);
   swap(&a, &b);
   // 7 3 printed
   printf("%i %i\n", a, b);
   return 0;
}

void swap(int *p, int *q)
{
   int   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
