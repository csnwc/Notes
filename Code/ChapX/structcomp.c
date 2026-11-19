#include <stdio.h>

typedef struct sct {
   char a;
   short b;
} sct;

int main(void)
{
   sct a = {1, 2};
   sct b;

   // This is fine.
   b = a;
   
   // NOT Allowed. gcc:
   // error: invalid operands to binary ==
   if(a==b){
      printf("Yes\n");
   }
}
