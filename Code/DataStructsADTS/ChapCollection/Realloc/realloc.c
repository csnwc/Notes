#include "specific.h"
#include "../coll.h"

coll* coll_init(void)
{
   coll *c = (coll*) ncalloc(sizeof(coll), 1);
   c->a = (datatype*) ncalloc(sizeof(datatype), FIXEDSIZE);
   c->size = 0;
   c->capacity= FIXEDSIZE;
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
      if(c->size >= c->capacity){
         c->a = (datatype*) realloc(c->a, sizeof(datatype)*c->capacity*SCALEFACTOR);
         c->capacity = c->capacity*SCALEFACTOR;
         if(c->a == NULL){
            on_error("Collection overflow");
         }
      }
   }
}

bool coll_remove(coll* c, datatype d)
{
   int i,j;
   bool found = false;
   for(i=0; i<coll_size(c); i++){
      if(c->a[i] == d){ 
          /* Shuffle end of array left one */
         c->size = c->size - 1;
         for(j=i; j<coll_size(c); j++){
            c->a[j] = c->a[j+1];
         }
         found = true;
      }
   }
   return found;
}

bool coll_free(coll* c)
{
   if(c==NULL){
      return true;
   }
   free(c->a);
   free(c);
   return true;
}
