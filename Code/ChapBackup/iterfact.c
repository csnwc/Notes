#include <stdio.h>

int fact(int a);

int main(void)
{

   int a, f;

   printf("Input a number :\n");
   scanf("%d", &a);
   f = fact(a);
   printf("%d! is %d\n", a, f);
   return(0);

}

int fact(int a)
{
 
   int i;
   int tot = 1;

   for(i=1; i<=a; i++){
      tot *= i;
   }
   return tot;

}
