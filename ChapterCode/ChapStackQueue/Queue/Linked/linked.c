#include "specific.h"
#include "../queue.h"

queue* queue_init(void)
{
   queue* q = (queue*) ncalloc(sizeof(queue), 1);
   return q;
}

void queue_enqueue(queue* q, datatype d)
{
   dataframe* f;
   if(q==NULL){
      return;
   }

   /* Copy the data */
   f = ncalloc(sizeof(dataframe), 1);
   f->i = d;

   /* 1st one */
   if(q->front == NULL){
      q->front = f;
      q->end = f;
      q->size = q->size + 1;
      return;
   }
   /* Not 1st */
   q->end->next = f;
   q->end = f;
   q->size = q->size + 1;
}

bool queue_dequeue(queue* q, datatype* d)
{
   dataframe* f;
   if((q==NULL) || (q->front==NULL) || (q->end==NULL)){
      return false;
   }
   f = q->front->next;
   *d = q->front->i;
   free(q->front);
   q->front = f;
   q->size = q->size - 1;
   return true;
}

bool queue_free(queue* q)
{
   if(q){
      dataframe* tmp;
      dataframe* p = q->front;
      while(p!=NULL){
         tmp = p->next;
         free(p);
         p = tmp;
      }
      free(q);
   }
   return true;
}

void queue_tostring(queue* q, char* str)
{
   dataframe *p;
   char tmp[ELEMSIZE];
   str[0] = '\0';
   if((q==NULL) || (q->front == NULL)){
      return;
   }
   p = q->front;
   while(p){
      sprintf(tmp, FORMATSTR, p->i); 
      strcat(str, tmp);
      strcat(str, "|");
      p = p->next;
   }
   str[strlen(str)-1] = '\0';
}

int queue_size(queue* q)
{
   if((q==NULL) || (q->front==NULL)){

      return 0;
   }
   return q->size;
}
























void queue_todot(queue* q, char* fname)
{
   dataframe *p;
   int n, i = 1;
   char str[DOTFILE];
   char tmp[DOTFILE];
   FILE* fp;
   sprintf(str, "digraph { rankdir=LR; node [shape=record]; subgraph cluster_0 { rankdir=LR; color=white;\n");
   p = q->front;
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
      sprintf(tmp, "n%d:e -> n%d:w;\n", i, i+1);
      strcat(str, tmp);
   }
   strcat(str ,"  front:e -> n1:data:w [tailclip=false];\n");
   strcat(str ,"  } node [shape=box, fixedsize=true, width=0.35, height=0.30]; front [color=white];\n");
   sprintf(tmp, "end [color=white]; end -> n%d:nw;\n}\n", n-1);
   strcat(str,tmp);
   sprintf(tmp, "%s%s", QUEUETYPE, fname);
   fp = nfopen(tmp, "wt");
   fprintf(fp, "%s\n", str);
   fclose(fp);
}
