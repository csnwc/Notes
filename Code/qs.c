#include <stdio.h>
#include <stdlib.h>

int intcompare(int *i, int *j);

int main(void)
{

   int a[10];
   int i;

   for(i=0; i<10; i++){
      a[i] = 9 - i;
   }

   qsort(a, 10, sizeof(int), intcompare);

   for (i=0; i<10; i++) printf(" %d",a[i]);
   printf("\n");
   return 0;

}

int intcompare(int *i, int *j)
{
   if (*i > *j)
      return (1);
   if (*i < *j)
      return (-1);
   return (0);
}
