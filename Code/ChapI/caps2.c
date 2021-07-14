#include <stdio.h>
#include <ctype.h>

int main(void)
{

   int   c;

   while ((c = getchar()) != '!')
      if (islower(c))
         putchar(toupper(c));
      else
         putchar(c);
   return 0;
}
