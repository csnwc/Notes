#include "specific.h"
#include "../stack.h"

#define DOTFILE 5000

stack* stack_init(void)
{
   stack* s = (stack*) ncalloc(sizeof(stack), 1);
   return s;
}

void stack_push(stack* s, datatype d)
{
   dataframe* f;
   if(s){
      f = ncalloc(sizeof(dataframe), 1);
      f->i = d;
      f->next = s->start;
      s->start = f;
      s->size = s->size + 1;
   }
      
}

bool stack_pop(stack* s, datatype* d)
{
   dataframe* f;
   if((s==NULL) || (s->start==NULL)){
      return false;
   }

   f = s->start->next;
   *d = s->start->i;
   free(s->start);
   s->start = f;
   s->size = s->size - 1;
   return true;
}

bool stack_peek(stack* s, datatype* d)
{
   if((s==NULL) || (s->start==NULL)){
      return false;
   }
   *d = s->start->i;
   return true;
}

void stack_tostring(stack* s, char* str)
{
   dataframe *p;
   char tmp[ELEMSIZE];
   str[0] = '\0';
   if((s==NULL) || (s->size <1)){
      return;
   }
   p = s->start;
   while(p){
      sprintf(tmp, FORMATSTR, p->i); 
      strcat(str, tmp);
      strcat(str, "|");
      p = p->next;
   }
   str[strlen(str)-1] = '\0';
}

bool stack_free(stack* s)
{
   if(s){
      dataframe* tmp;
      dataframe* p = s->start;
      while(p!=NULL){
         tmp = p->next;
         free(p);
         p = tmp;
      }
      free(s);
   }
   return true;
}

























void stack_todot(stack* s, char* fname)
{
   dataframe *p;
   int n, i = 1;
   char str[DOTFILE];
   char tmp[DOTFILE];
   FILE* fp;
   sprintf(str, "digraph { rankdir=TB; node [shape=record]; subgraph cluster_0 { rankdir=TB; color=white;\n");
   p = s->start;
   while(p){
      sprintf(tmp, "n%d [label=\"{<data>", i++);
      strcat(str, tmp);
      sprintf(tmp, FORMATSTR, p->i);
      strcat(str, tmp);
      p = p->next;
      if(p){
         strcat(str, "|next}\"];\n");
      }
      else{
         strcat(str, "|&#8226;}\"];\n");
      }
   }
   n = i;
   /* One edge less than nodes */
   for(i=1; i<n-1; i++){
      sprintf(tmp, "n%d:s -> n%d:n;\n", i, i+1);
      strcat(str, tmp);
   }
   strcat(str ,"  top:s -> n1:data:n [tailclip=false];\n");
   strcat(str ,"  } node [shape=box, fixedsize=true, width=0.35, height=0.30]; top [color=white];\n}\n");
   sprintf(tmp, "%s%s", STACKTYPE, fname);
   fp = nfopen(tmp, "wt");
   fprintf(fp, "%s\n", str);
   fclose(fp);
}
