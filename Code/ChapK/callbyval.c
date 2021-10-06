#include <stdio.h>

void changex(int x);

int main(void)
{
   int x = 1;

   changex(x);
   printf("%i\n", x);
   return 0;
}

void changex(int x)
{
   x = x + 1;
}
