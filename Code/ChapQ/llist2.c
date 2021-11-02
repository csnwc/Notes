#include "coll.h"
#include "Fixed/specific.h"

int main(void)
{
   coll* c;
   int i;

   printf("Please type some numbers :");
   c = coll_init();
   while(scanf("%i", &i) == 1){
      coll_add(c, i);
   }
   // Do print etc.
   coll_free(c);
   return 0;
}
