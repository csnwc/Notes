#include <stdio.h>

#define R 3
#define C 5

int main(void)
{

   int a[R][C];
   int y = 2, x = 3;

   a[y][x] = 74;

   printf("%p\n", a);
   printf("%p\n", &a[0][0]);

   return 0;
}
