/* Outputs characters twice */

#include <stdio.h>

int main(void)
{

   char c;

   while (1) {
      c = getchar();
      putchar(c);
      putchar(c);
   }

   return 0;
}
