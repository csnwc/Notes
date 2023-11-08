#include <stdio.h>
#include <stdlib.h>
#include "general.h"

typedef struct data{
   int i;
   struct data* next;
} Data;

Data* allocateData(int i);
void printList(Data* l);

int main(void)
{
   int i;
   Data* start, *current;
   start = current = NULL;
   printf("Enter the first number: ");
   if(scanf("%i", &i) == 1){
      start = current = allocateData(i);
   }
   else{
      on_error("Couldn't read an int");
   }

   printf("Enter more numbers: ");
   while(scanf("%i", &i) == 1){
      current->next = allocateData(i);
      current = current->next;
   }
   printList(start);
   return 0; // Should Free List
} 

Data* allocateData(int i)
{
   Data* p;
   p = (Data*) ncalloc(1, sizeof(Data));
   p->i = i;
   // Not really required
   p->next = NULL;
   return p;
}

void printList(Data* l)
{
   printf("\n");
   do{
      printf("Number : %i\n", l->i);
      l = l->next;
   }while(l != NULL);
   printf("END\n");
}

Data* inList(Data* n, int i)
{
   do{
      if(n->i==i){
         return n;
      }
      n = n->next;
   }while(n != NULL);
   return NULL;
}

void printList_r(Data* l)
{
   // Recursive Base-Case
   if(l == NULL) return;

   printf("Number: %i\n", l->i);
   printList_r(l->next);
}
