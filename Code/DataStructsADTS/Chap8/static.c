#include <stdio.h>

#define NUMFUNCCALLS 1000

void f(void);

int main(void)
{
   int i;
   for(i=0; i<NUMFUNCCALLS; i++){
      f();
   }
   return 0;
}

void f(void)
{
   int cnt = 0;
   cnt++;
   printf("I've been in function f() %d times\n", cnt);
}
