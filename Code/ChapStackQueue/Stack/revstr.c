#include "specific.h"
#include "stack.h"

int main(void)
{
   char str[100];
   unsigned int i;
   stack* s;
   datatype d;

   strcpy(str, "A man, a plan, a cat, a canal – Panama!");

   s = stack_init();
   for(i=0; i< strlen(str); i++){
      stack_push(s, str[i]);
   }
   for(i=0; i< strlen(str); i++){
      assert(stack_pop(s, &d));
      str[i] = d;
   }
   printf("%s\n", str);
   stack_free(s);
   return 0;
}
