#include <stdio.h>

void fnc1(int x);

int main(void)
{

   int x = 1;

   fnc1(x);
   printf("%d\n", x);
}

void fnc1(int x)
{
   x = x + 1;
}
