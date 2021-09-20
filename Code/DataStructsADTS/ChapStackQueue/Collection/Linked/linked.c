#include "specific.h"
#include "../coll.h"

coll* coll_init(void)
{
   coll *c = (coll*) ncalloc(sizeof(coll), 1);
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
   dataframe* f;
   if(c == NULL || c->start==NULL){
      return false;
   }
   f = c->start;
   do{
      if(f->i == d){ 
          return true;
      }
      f = f->next;
   }while(f != NULL);
   return false;
}

void coll_add(coll* c, datatype d)
{
   dataframe* f;
   if(c){
      f = ncalloc(sizeof(dataframe), 1);
      f->i = d;
      f->next = c->start;
      c->start = f;
      c->size = c->size + 1;
   }
      
}

bool coll_remove(coll* c, datatype d)
{
   dataframe* f1, *f2;
   if((c==NULL) || (c->start==NULL)){
      return false;
   }

   /* If Front */
   if(c->start->i == d){
      f1 = c->start->next;
      free(c->start);
      c->start = f1;
      c->size = c->size - 1;
      return true;
   }

   f1 = c->start;
   f2 = c->start->next;
   do{
      if(f2->i == d){
         f1->next = f2->next;
         free(f2); 
         c->size = c->size - 1;
         return true;
      }
      f1 = f2;
      f2 = f1->next;
   }while(f2 != NULL);
   return false;
}

bool coll_free(coll* c)
{
   if(c){
      dataframe* tmp;
      dataframe* p = c->start;
      while(p!=NULL){
         tmp = p->next;
         free(p);
         p = tmp;
      }
      free(c);
   }
   return true;
}
