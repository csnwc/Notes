#include "specific.h"
#include "bst.h"

int main(void)
{

   bst* b;

   printf("Test BST (%s) Start ... ", BSTTYPE);

   assert(bst_size(NULL)==0);
   assert(!bst_insert(NULL, 10));
   assert(!bst_isin(NULL, 50));
   b = bst_init();
   assert(!bst_isin(NULL, 50));
   assert(bst_size(b)==0);
   assert(bst_insert(b, 50));
   assert(bst_size(b)==1);
   assert(bst_isin(b, 50));
   assert(bst_insert(b, 10));
   assert(bst_size(b)==2);
   assert(bst_isin(b, 10));
   assert(bst_insert(b, 90));
   assert(bst_size(b)==3);
   assert(bst_isin(b, 90));

   assert(bst_free(b));
   printf("END\n");
   return 0;

}
