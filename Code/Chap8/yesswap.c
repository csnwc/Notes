#include <stdio.h>
#include "pointers.h"

void change(address p);

int main(void)
{
   int v = 1;
   change(get_address(v));
   printf("%d\n", v);
   return 0;
}

void change(address p)
{
   writevia(p) = 2;
}
