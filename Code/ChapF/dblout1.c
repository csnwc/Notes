// Outputs characters twice

#include <stdio.h>

int main(void)
{

   char c;

   do{
      c = getchar();
      putchar(c);
      putchar(c);
   }while(c != '!');
   putchar('\n');

   return 0;
}
