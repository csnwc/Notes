#include <stdio.h>
#include <stdlib.h>

int intcompare(const void *a, const void *b);

int main(void)
{
   int a[10];

   for(int i=0; i<10; i++){
      a[i] = 9 - i;
   }

   qsort(a, 10, sizeof(int), intcompare);

   for (int i=0; i<10; i++){
      printf(" %d",a[i]);
   }
   printf("\n");
   return 0;

}

int intcompare(const void *a, const void *b)
{
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ia  - *ib;
}
