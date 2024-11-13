#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXEXPR 400
struct prog{
        char str[MAXEXPR];
        int count;
};
typedef struct prog Prog;
void Op(Prog *p);
int isop(char c);
void Expr(Prog *p);
#define ON_ERROR(S) {fprintf(stderr, "%s", S);\
                     exit(EXIT_FAILURE);}
int main(void)
{
   Prog p;
   p.count = 0;
   if(scanf("%[A-Z-+()]s", p.str) != 1){
      ON_ERROR("Couldn't read your expression ?\n");
   }
   Expr(&p);
   printf("Parsed OK !\n");
   return 0;
}

int isop(char c)
{
   if(c=='+' || c=='-' || c=='*' || c=='/'){
      return 1;
   }
   return 0;
}

void Op(Prog *p)
{
   if(!isop(p->str[p->count]))
      ON_ERROR("I was expecting a letter ?\n");
}
void Expr(Prog *p)
{
   if(p->str[p->count] == '('){
      p->count = p->count + 1;
      Expr(p);
      p->count = p->count + 1;
      if(p->str[p->count] != ')'){
         ON_ERROR("I was expecting a ) ?\n");
      }
   }
   else if(p->str[p->count] == '-'){
      p->count = p->count + 1;
      Expr(p);
   }
   // Note Look-Ahead
   else if(isop(p->str[p->count+1])){
      if(isupper(p->str[p->count])){
         p->count = p->count + 1;
         Op(p);
         p->count = p->count + 1;
         Expr(p);
      }
   }
   else{
      if(!isupper(p->str[p->count]) ||
         isupper(p->str[p->count+1])){
         ON_ERROR("Expected a single letter ?\n");
      }
   }
}
