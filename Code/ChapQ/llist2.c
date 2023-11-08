#include "coll.h"
#include "Fixed/specific.h"

int main(void)
{
   printf("Please type some numbers :");
   coll* c = coll_init();
   int i;
   while(scanf("%i", &i) == 1){
      coll_add(c, i);
   }
   // Do print etc.
   coll_free(c);
   return 0;
}
