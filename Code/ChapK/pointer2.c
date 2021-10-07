#include <stdio.h>

int main(void)
{

   int i;
   int* p;

   p = &i;
   printf("Please Type a number : ");
   scanf("%i", &i);
   printf("%i\n", i);
   printf("Please Type a number : ");
   scanf("%i", p);
   printf("%i\n", i);

   return 0;

}
