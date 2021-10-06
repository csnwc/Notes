#include <stdio.h>

#define MIN(A, B) ((A)<(B)?(A):(B))

int main(void)
{

   int j, k, m;

   printf("Input two integers: ");
   scanf("%i%i", &j, &k);
   m = MIN(j, k);
   printf("Minimum is %i\n", m);
   return 0;

}
