#include "specific.h"
#include "coll.h"

int main(void)
{
   coll* c;

   printf("Please type some numbers :");
   c = coll_init();
   while(scanf("%d", &i) == 1){
      col_add(c, i);
   }
   /* Do print etc. */
   coll_free(c);
   return 0;
}
