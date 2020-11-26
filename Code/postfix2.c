#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "stack.h"
#include "queue.h"

void PrintPostFix(char *infix);
int isoperator(char c);

int main(void)
{

   char infix[] = "(((A/(B*C))+(D*E))-(A*C))";
   PrintPostFix(infix);
   return 0;

}

int isoperator(char c)
{

   if(c == '+' || c == '-' || c == '*' || c == '/'){
      return 1;
   }
   else{
      return 0;
   }

}


void PrintPostFix(char *infix)
{

   Queue q;
   Stack s;
   int ip = 0;
   char c, d;
   int priority[256];

   InitialiseQueue(&q);
   InitialiseStack(&s);
   Push(&s, '\0');
   
   priority['*'] = 2; priority['/'] = 2; priority['+'] = 1;
   priority['-'] = 1; priority['('] = 3; priority[')'] = 0;

   do{
      c = infix[ip++];
      if(isupper(c))
         InsertQueue(c, &q);
      else if(c == ')'){
            d = Pop(&s);
            while(d != '('){
               InsertQueue(d, &q);
               d = Pop(&s);
            }
      }
      else if(c == '\0'){
               while(!EmptyStack(&s)){
                  d = Pop(&s);
                  InsertQueue(d, &q);
               }
      }
      else if(c == '(' || isoperator(c)){
                  d = Pop(&s);
                  while(priority[(int)d] >= priority[(int)c] && isoperator(d)){
                     InsertQueue(d, &q);
                     d = Pop(&s);
                  }
                  Push(&s, d);
                  Push(&s, c);
      }
      else{
         printf("Invalid Token \"%c\"\n", c);
         exit(2);
      }
   }while(c != '\0');

   for(ip=0; !EmptyQueue(q); ip++)
      printf("%c", RemoveQueue(&q));
   printf("\n");

}

void InitialiseQueue(Queue *q)
{

   q->front = 0;
   q->back = 0;

}

char RemoveQueue(Queue *q)
{

   char c;

   c = q->n[q->front];
   q->front = (q->front + 1)%MAX_QUEUE;

   return c;

}

void InsertQueue(char c, Queue *q)
{

   q->n[q->back] = c;
   q->back = (q->back + 1)%MAX_QUEUE;

}

int EmptyQueue(Queue q)
{

   if(q.front == q.back) return 1;
   return 0;

}

int EmptyStack(Stack *s)
{
   if(s->top == 0) return 1;
   return 0;
}

void InitialiseStack(Stack *s)
{

   s->top = 0;

}

void Push(Stack *s, char c)
{

   assert(s->top < STACKSIZE);
   s->stk[s->top].i = c;
   s->top = s->top + 1;

}


char Pop(Stack *s)
{

   assert(s->top > 0);
   s->top = s->top - 1;
   return s->stk[s->top].i;

}
