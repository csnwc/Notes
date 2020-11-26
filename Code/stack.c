#include <stdio.h>
#include <assert.h>

#define STACKSIZE 200

struct thestack{
   int stk[STACKSIZE];
   int top;
};

typedef struct thestack Stack;

void InitialiseStack(Stack *s);
void Push(Stack *s, int n);
int Pop(Stack *s);

int main(void)
{

   Stack s;
   InitialiseStack(&s);

   Push(&s, 12);
   Push(&s, 117);
   Push(&s, 13);
   Push(&s, 15);
   printf("%d\n", Pop(&s));
   printf("%d\n", Pop(&s));
   printf("%d\n", Pop(&s));
   printf("%d\n", Pop(&s));
   printf("%d\n", Pop(&s));

   return 0;

}

void InitialiseStack(Stack *s)
{

   s->top = 0;

}

void Push(Stack *s, int n)
{

   assert(s->top < STACKSIZE);
   s->stk[s->top] = n;
   s->top = s->top + 1;

}

int Pop(Stack *s)
{

   assert(s->top > 0);
   s->top = s->top - 1;
   return s->stk[s->top];

}
