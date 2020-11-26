#include <stdio.h>

void binary(int i);

int main(void)
{

   int i = 256 + 16 + 1;

   binary(i);
   printf("\n");
   return 0;

}

void binary(int i)
{

   if(i == 0)
      return;

   binary(i>>1);

   if((i&1) == 0)
      printf("0");
   else
      printf("1");


}
