#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGGESTNAME 50

struct llist {
   char word[BIGGESTNAME];
   struct llist *next;
};

int main(void)
{
   struct llist *head, *cp;

   printf("Enter a list of words.\n");
   cp = head = calloc(1, sizeof(struct llist));
   while(scanf("%s", cp->word)==1){
      cp->next = calloc(1, sizeof(struct llist));
      cp = cp->next;
   };

   cp = head;
   printf("The words were :\n");
   while(cp->next != NULL){
      printf("%s\n", cp->word);
      cp = cp->next;
   };
   return 0;
}
