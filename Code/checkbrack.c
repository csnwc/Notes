#include <stdio.h>
#include <assert.h>

/* Function proptotypes & definitions required
   for an Integer stack (see previous notes )  */
#include "stack.h"

#define MAXEXPR 400
void CheckBrackets(char *str);
int MatchBracket(char c, char d);

int main(void)
{

   char name[MAXEXPR];

   if(!gets(name)){
      printf("Cannot read string ?\n");
      exit(2);
   }


   CheckBrackets(name);

   return 0;

}

int MatchBracket(char c, char d)
{
   if(c == '{' && d == '}') return 1;
   if(c == '(' && d == ')') return 1;
   if(c == '[' && d == ']') return 1;
   return 0;
}

void CheckBrackets(char *str)
{

   char c;
   Stack s;
   InitialiseStack(&s);

   while(*str){

      if(*str == '{' || *str == '(' || *str == '['){
         Push(&s, (int)*str);
      }
      if(*str == '}' || *str == ')' || *str == ']'){
         c = Pop(&s);
         if(!MatchBracket(c, *str)){
            printf("Parse Error !\n");
            exit(2);
         }
      }
      str++;
   }

   if(!Empty(&s)){
      printf("Parse Error !\n");
      exit(2);
   }
   printf("Everything OK\n");

}

void InitialiseStack(Stack *s)
{

   s->top = 0;

}

int Empty(Stack *s)
{
   if(s->top == 0) return 1;
   return 0;
}
void Push(Stack *s, int n)
{

   assert(s->top < STACKSIZE);
   s->stk[s->top].i = n;
   s->top = s->top + 1;

}

int Pop(Stack *s)
{

   assert(s->top > 0);
   s->top = s->top - 1;
   return s->stk[s->top].i;

}
