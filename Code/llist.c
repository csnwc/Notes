#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 20

struct node{
	char name[MAXNAME];
	struct node *next;
};

typedef struct node Node;

Node *AllocateNode(char *s);
void PrintList(Node *l);

int main(void)
{

   char name[MAXNAME];
   Node *start, *current;

   printf("Enter the first name : ");
   if(scanf("%s", name) == 1)
      start = current = AllocateNode(name);
   else return 1;

   printf("Enter more names : ");
   while(scanf("%s", name) == 1){
      current->next = AllocateNode(name);
      current = current->next;
   }
   PrintList(start);
   return 0;
} 

Node *AllocateNode(char *s)
{

   Node *p;

   p = (Node *)malloc(sizeof(Node));

   if(p==NULL){
      printf("Cannot Allocate Node\n");
      exit(2);
   }

   strcpy(p->name, s);
   p->next = NULL;
   return p;

}

void PrintList(Node *l)
{

   printf("\n");
   do{
      printf("Name : %s\n", l->name);
      l = l ->next;
   }while(l != NULL);
   printf("END\n");

}
