#include "specific.h"
#include "../coll.h"

coll* coll_init(void)
{
   coll *c = (coll*) ncalloc(sizeof(coll), 1);
   c->size = 0;
   return c;
}

int coll_size(coll* c)
{
   if(c==NULL){
      return 0;
   }
   return c->size;
}

bool coll_isin(coll* c, datatype d)
{
   int i;
   for(i=0; i<coll_size(c); i++){
      if(c->a[i] == d){ 
          return true;
      }
   }
   return false;
}

void coll_add(coll* c, datatype d)
{
   if(c){
      c->a[c->size] = d;
      c->size = c->size + 1;
      if(c->size >= FIXEDSIZE){
         on_error("Collection overflow");
      }
   }
}

bool coll_remove(coll* c, datatype d)
{
   int i,j;
   for(i=0; i<coll_size(c); i++){
      if(c->a[i] == d){ 
         /* Shuffle end of array left one */
         for(j=i; j<coll_size(c); j++){
            c->a[j] = c->a[j+1];
         }
         c->size = c->size - 1;
         return true;
      }
   }
   return false;
}

bool coll_free(coll* c)
{
   free(c);
   return true;
}
