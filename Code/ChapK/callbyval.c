#include <stdio.h>

void changex(int x);

int main(void)
{
   int x = 1;

   changex(x);
   printf("%d\n", x);
}

void changex(int x)
{
   x = x + 1;
}
