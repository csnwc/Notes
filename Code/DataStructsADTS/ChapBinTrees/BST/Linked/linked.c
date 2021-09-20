#include "specific.h"
#include "../bst.h"

void _freeframes(dataframe* frame);
dataframe* _insert(dataframe* t, datatype d);
bool _isin(dataframe* t, datatype d);
int _size(dataframe* b);

bst* bst_init(void)
{
   bst* b = (bst*) ncalloc(1, sizeof(bst));
   return b;
}

int bst_size(bst* b)
{
   if(b==NULL){
      return 0;
   }
   return _size(b->top);
}

bool bst_insert(bst* b, datatype d)
{
   if(b==NULL){
      return false;
   }
   if(b->top == NULL){
      b->top = _insert(b->top, d);
      return true;
   }
   _insert(b->top, d);
   return true;
}

bool bst_isin(bst* b, datatype d)
{
   if(b==NULL){
      return false;
   }
   return _isin(b->top, d);
}

bool bst_insertarray(bst* b, datatype* a, int n)
{
   int i;
   if((b==NULL) || (a==NULL) || (n<=0)){
      return false;
   }
   for(i=0; i<n; i++){
      bst_insert(b, a[i]);
   }
   return true;
}

bool bst_free(bst* b)
{
   if(b==NULL){ 
      return false;
   }
   _freeframes(b->top);
   free(b);
   return true;
}

/*****************************************************************/
/*                      Auxilary Functions                       */
/*****************************************************************/

/* Based on geekforgeeks.org */
dataframe* _insert(dataframe* t, datatype d)
{
    dataframe* f;
    /* If the tree is empty, return a new frame */
    if (t == NULL){
       f = ncalloc(sizeof(dataframe), 1);
       f->d = d;
       return f;
    }
    /* Otherwise, recurs down the tree */
    if (t->d < d){
        t->left = _insert(t->left, d);
    }
    else if(t->d > d){
       t->right = _insert(t->right, d);
    }
    /* return the (unchanged) dataframe pointer */
    return t;
}

bool _isin(dataframe* t, datatype d)
{
   if(t==NULL){
      return false;
   }
   if(t->d == d){
      return true;
   }
   if(t->d < d){
      return _isin(t->left,  d);
   }
   else{
      return _isin(t->right, d);
   }
   return false;
}

void _freeframes(dataframe* t)
{
   if(t== NULL){
      return;
   }
   _freeframes(t->left);
   _freeframes(t->right);
   free(t);
}

int _size(dataframe* t)
{
   if(t==NULL){
      return 0;
   }
   return 1 + _size(t->left) + _size(t->right);
}
