#include <stdio.h>
#include <ctype.h>

int isoperator(char c);

void main(void)
{

   char infix[] = "A+(B/D)";
   char prfix[256];
   int inpri[256];
   int stpri[256];
   char stack[100];
   int sp = 0;
   int ip = 0;
   int op = 0;
   char c, d;
   
   inpri['*'] = 2;
   inpri['/'] = 2;
   inpri['+'] = 1;
   inpri['-'] = 1;
   inpri['('] = 3;
   inpri[')'] = 0;
   stpri['*'] = 2;
   stpri['/'] = 2;
   stpri['+'] = 1;
   stpri['-'] = 1;
   stpri['('] = 3;
   stpri[')'] = 0;

   do{
     c = infix[ip++];

      if(isupper(c)){
         prfix[op++] = c;
      }
      else{
         if(c == ')'){
            sp--;
            d = stack[sp];
            while(d != '('){
               prfix[op++] = d;
               sp--;
               d = stack[sp];
            }
         }
         else{
            if(c == '\0'){
               do{
                  sp--;
                  d = stack[sp];
                  prfix[op++] = d;
               }while(sp >= 0);
            }
            else{
               if(c == '(' || isoperator(c)){
                  sp--;
                  d = stack[sp];
                  while(stpri[(int)d] >= inpri[(int)c] && isoperator(d)){
                     prfix[op++] = d;
                     sp--;
                     d = stack[sp];
                  }
                  stack[sp++] = d;
                  stack[sp++] = c;
               }
               else{
                  printf("Invalid Token \"%c\"\n", c);
                  exit(2);
               }
            }
         }
      }
   }while(c != '\0');
   prfix[op] = '\0';
   printf("%s\n", prfix);

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
