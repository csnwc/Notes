#include <stdio.h>
#include <stdlib.h>
#include "general.h"

struct node{
   int i;
   struct node *next;
};

typedef struct node Node;

Node *AllocateNode(int i);
void PrintList(Node *l);

int main(void)
{

   int i;
   Node* start, *current;

   start = current = NULL;
   printf("Enter the first number: ");
   if(scanf("%d", &i) == 1){
      start = current = AllocateNode(i);
   }
   else{
      on_error("Couldn't read an int");
   }

   printf("Enter more numbers: ");
   while(scanf("%d", &i) == 1){
      current->next = AllocateNode(i);
      current = current->next;
   }
   PrintList(start);
   /* Should Free List */
   return 0;
} 

Node *AllocateNode(int i)
{
   Node *p;
   p = (Node*) ncalloc(1, sizeof(Node));
   p->i = i;
   /* Not really required */
   p->next = NULL;
   return p;
}

void PrintList(Node *l)
{
   printf("\n");
   do{
      printf("Number : %d\n", l->i);
      l = l->next;
   }while(l != NULL);
   printf("END\n");
}
