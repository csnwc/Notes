// Store a list of numbers (length unknown) 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXNUM 20
#define ENDNUM 10

struct data {
   int num;
   struct data* next;
};
typedef struct data data;

void addtolist(data* tail);
void printlist(data* st);

int main(void)
{
   data *p, *start;
   start = p = calloc(1, sizeof(data));
   assert(p);
   p->num = rand()%MAXNUM;
   // Add other numbers to the list
   do{
      addtolist(p);
      p = p->next;
   }while(p->num != ENDNUM);
   printlist(start);
   // Need to free up list - not shown here ...
   return 0;
}

// Create some new space and store number in it
void addtolist(data* tail)
{
   tail->next = calloc(1, sizeof(data));
   assert(tail);
   tail = tail->next;
   tail->num = rand()%MAXNUM;
}

void printlist(data* st)
{
   while(st != NULL){
      printf("%i ", st->num);
      st = st->next;
   };
   printf("\n");
}
