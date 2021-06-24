#include <stdio.h>

int main(void)
{

   printf("char       :%3ld\n", sizeof(char));
   printf("short      :%3ld\n", sizeof(short));
   printf("long       :%3ld\n", sizeof(long));
   printf("unsigned   :%3ld\n", sizeof(unsigned));
   printf("long long  :%3ld\n", sizeof(long long));
   printf("float      :%3ld\n", sizeof(float));
   printf("dbl        :%3ld\n", sizeof(double));
   printf("long dbl   :%3ld\n", sizeof(long double));
   printf("\n");

   return 0;
}
