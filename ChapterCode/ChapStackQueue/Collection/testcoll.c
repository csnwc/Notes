#include "specific.h"
#include "coll.h"

int main(void)
{
   int i;
   coll* c;
   printf("Test Collection (%s) Start ... ", COLLTYPE);
   assert(coll_free(NULL));
   assert(coll_size(NULL) == 0);
   coll_add(NULL, 10);
   c = coll_init();
   assert(coll_size(c) == 0);
   coll_add(c, 10);
   assert(coll_size(c) == 1);
   assert(coll_isin(c, 10));
   assert(!coll_isin(c, 20));
   assert(coll_remove(c, 10));
   assert(!coll_isin(c, 10));
   assert(coll_size(c) == 0);
   coll_add(c, 10);
   coll_add(c, 5);
   assert(coll_size(c) == 2);
   coll_add(c, 30);
   assert(coll_size(c) == 3);
   coll_add(c, 150);
   assert(coll_size(c) == 4);
   coll_add(c, 20);
   assert(coll_size(c) == 5);
   assert(coll_remove(c, 5));
   assert(coll_size(c) == 4);
   assert(coll_remove(c, 10));
   assert(coll_size(c) == 3);
   assert(coll_remove(c, 20));
   assert(coll_size(c) == 2);
   for(i=0; i<4000; i++){
      assert(coll_size(c) == i+2);
      coll_add(c,i);
   }
   assert(coll_free(c));

   printf("End\n");
   return 0;
}
