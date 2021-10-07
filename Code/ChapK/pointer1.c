#include <stdio.h>

int main(void)
{

   int i = 5; 
   int* p = &i;
   printf("%i\n", *p);
   i = 17; 
   printf("%i\n", *p);
   *p = 99;
   printf("%i\n", i);

   return 0;

}
