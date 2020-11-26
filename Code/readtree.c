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
void T_PrintTree(Node *r, int d, int off, Dirn w, char tree[100][100]);
void PrintTree(Node *t);
void RightGoes(Node *t, int *k);

int main(void)
{

   char str[100];
   Node *top;

   gets(str);
   printf("%s\n", str);
   DeleteSpaces(str);
   printf("%s\n", str);
   top = Process(str);

   PrintTree(top);
   return 0;

}

void PrintTree(Node *t)
{

   int i, j;
   char tree[100][100];

   for(j=0; j<100; j++){
      for(i=0; i<100; i++){
         tree[j][i] = ' ';
      }
   }
   T_PrintTree(t, 1, 1, NONE, tree);
   for(j=0; j<10; j++){
      for(i=0; i<20; i++){
         printf("%c", tree[j][i]);
      }
      printf("\n");
   }

}

void T_PrintTree(Node *t, int d, int off, Dirn w, char tree[100][100])
{

   int i, j;

   if(t == NULL){
      return;
   }

   tree[d*2][off*2] = t->letter;
   if(w == LEFT){
      tree[d*2-1][off*2] = '|';
   }
   T_PrintTree(t->left, d+1, off, LEFT, tree);

   j = 0;
   RightGoes(t->left, &j);

   if(t->right != NULL){
      for(i=off*2+1; i<(off+j+1)*2; i++)
            tree[d*2][i] = '-';
      T_PrintTree(t->right, d, off+j+1, RIGHT, tree);
   }

}

void RightGoes(Node *t, int *k)
{

   if(t == NULL){
      return;
   }

   RightGoes(t->left, k);
   if(t->right != NULL){
      *k = *k + 1;
      RightGoes(t->right, k);
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
