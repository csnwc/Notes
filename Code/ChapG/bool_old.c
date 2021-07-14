#include <stdio.h>
#include <assert.h>

typedef enum bool {false, true} bool;

int main(void)
{

   bool b = true;
   if (b){
      printf("It's true!\n");
   }
   else{
      printf("It's false!\n");
   }
   return 0;
}
