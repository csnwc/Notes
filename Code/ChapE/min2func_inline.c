#include <stdio.h>

static inline int min(int a, int b);

int main(void)
{

   int j, k, m;

   printf("Input two integers: ");
   scanf("%d%d", &j, &k);
   m = min(j, k);
   printf("Minimum is %d\n", m);
   return 0;

}

inline int min(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}
