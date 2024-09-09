#include "specific.h"
#include "stack.h"

int main(void)
{
   datatype d;
   char str[1000];
   int i;
   stack* s;
   printf("Test Stack (%s) Start ... ", STACKTYPE);

   assert(stack_free(NULL));
   assert(!stack_peek(NULL, &d));
   stack_push(NULL, 10);
   stack_tostring(NULL, str);
   assert(strcmp(str, "")==0);

   s = stack_init();
   assert(!stack_pop(s, &d));
   stack_tostring(s, str); assert(strcmp(str, "")==0);
   assert(!stack_peek(s, &d));
   stack_push(s, 10);
   assert(stack_peek(s, &d));
   assert(d == 10);
   stack_tostring(s, str);
   assert(strcmp(str, "10")==0);

   assert(stack_pop(s, &d)); assert(d==10);
   assert(!stack_peek(s, &d));
   stack_push(s, 10);
   stack_push(s, 5);
   stack_push(s, 30);
   stack_push(s, 150);
   stack_push(s, 20);
   stack_tostring(s, str);
   assert(strcmp(str, "20|150|30|5|10")==0);
   stack_todot(s, "s.dot");
   assert(stack_pop(s,&d)); assert(d==20);
   assert(stack_pop(s,&d)); assert(d==150);
   assert(stack_peek(s, &d));
   assert(d == 30);
   assert(stack_pop(s,&d)); assert(d==30);
   for(i=0; i<400000; i++){
      stack_push(s,i);
   }
   for(i=399999; i>=0; i--){
      assert(stack_pop(s,&d)); assert(d==i);
   }
   assert(stack_pop(s,&d)); assert(d==5);
   assert(stack_peek(s, &d));
   assert(d == 10);
   assert(stack_pop(s,&d)); assert(d==10);
   assert(!stack_peek(s, &d));
   assert(stack_free(s));
   printf("End\n");
   return 0;
}
