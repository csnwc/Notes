#include <stdio.h>

int min(int a, int b);

int main(void)
{

   int j, k, m;

   printf("Input two integers: ");
   scanf("%i%i", &j, &k);
   m = min(j, k);
   printf("\nOf the two values %i and %i, " \
   "the minimum is %i.\n\n", j, k, m);
   return 0;

}

int min(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}
