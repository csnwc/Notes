#include <stdio.h>

int main(void)
{

   int i[100];
   printf("\n");
   printf("char\t\t:%3ld\n", sizeof(char));
   printf("short\t\t:%3ld\n", sizeof(short));
   printf("int\t\t:%3ld\n", sizeof(i));
   printf("long\t\t:%3ld\n", sizeof(long));
   printf("unsigned\t:%3ld\n", sizeof(unsigned));
   printf("float\t\t:%3ld\n", sizeof(float));
   printf("dbl\t\t:%3ld\n", sizeof(double));
   printf("long dbl\t:%3ld\n", sizeof(long double));
   printf("\n");

   return 0;
}
