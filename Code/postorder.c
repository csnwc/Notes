#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
        char letter;
	struct node *left;
	struct node *right;
};

enum dirn {NONE, LEFT, RIGHT};
typedef enum dirn Dirn;

typedef struct node Node;

Node *CreateNode();
void DeleteSpaces(char *s);
Node *Process(char *s);
void PrintPostOrder(Node *t);

int main(void)
{

   char str[100];
   Node *top;

   gets(str);
   printf("%s\n", str);
   DeleteSpaces(str);
   printf("%s\n", str);
   top = Process(str);

   PrintPostOrder(top);

   return 0;

}

void PrintPostOrder(Node *t)
{

   if(t != NULL){
      PrintPostOrder(t->left);
      PrintPostOrder(t->right);
      printf("%c\n", t->letter);
   }

}

void DeleteSpaces(char *s)
{

   int i, j;
   char r[100];

   i = j = 0;
   while(s[i] != '\0'){
      if(s[i] != ' ')
         r[j++] = s[i];
      i++;
   }
   r[j] = '\0';
   strcpy(s, r);

}

Node *Process(char *s)
{

   int i, j;
   int mb;
   char left[100];
   char right[100];
   Node *t;

   if(!strncmp(s, "()", 2)){
      return (Node *)NULL;
   }

   mb = 0;
   i = 2;
   j = 0;
   do{
      left[j++] = s[i];
      if(s[i] == '('){
         mb++;
      }
      if(s[i] == ')'){
         mb--;
      }
      i++;
   }while(mb != 0);
   left[j] = '\0';

   j = 0;
   do{
      right[j++] = s[i];
      if(s[i] == '('){
         mb++;
      }
      if(s[i] == ')'){
         mb--;
      }
      i++;
   }while(mb != 0);
   right[j] = '\0';

   t = CreateNode();
   t->left = Process(left);
   t->right = Process(right);
   t->letter = s[1];
   return t;

}

Node *CreateNode()
{

   Node *j;

   j = (Node *)calloc(sizeof(Node), 1);
   return j;

}
