#include <stdio.h>

void change(int i);

int main(void)
{
   int v = 1;
   change(v);
   printf("%d\n", v);
   return 0;
}

void change(int v)
{
   v = 2;
}
