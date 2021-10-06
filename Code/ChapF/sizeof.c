#include <stdio.h>

int main(void)
{

   printf("char       :%3li\n", sizeof(char));
   printf("short      :%3li\n", sizeof(short));
   printf("long       :%3li\n", sizeof(long));
   printf("unsigned   :%3li\n", sizeof(unsigned));
   printf("long long  :%3li\n", sizeof(long long));
   printf("float      :%3li\n", sizeof(float));
   printf("dbl        :%3li\n", sizeof(double));
   printf("long dbl   :%3li\n", sizeof(long double));
   printf("\n");

   return 0;
}
