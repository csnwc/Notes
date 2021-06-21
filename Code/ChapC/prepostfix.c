#include <stdio.h>

int main(void)
{
   int a, c = 0;
   a = ++c;
   int b = c++;
   printf("%d %d %d\n", a, b, ++c);
   return 0;
}
