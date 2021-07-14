/* Outputs characters twice */

#include <stdio.h>

#define CAPS ('A' - 'a')

int main(void)
{   
   int   c;
   while ((c = getchar()) != '!'){
      if (c >= 'a' && c <= 'z'){
          putchar(c + CAPS);
      }
      else{
         putchar(c);
      }
   }
   return 0;
}
