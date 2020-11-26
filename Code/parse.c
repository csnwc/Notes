#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct assignment{
	int j;
	char p[250];
};
typedef struct assignment Assignment;

/* 
<LINE> 	     ::= <VARIABLE><RHS> | <PFIX><VARIABLE>";"
<RHS> 	     ::= <ASSIGN><EXPRESSION> | <PFIX>";"
<ASSIGN>     ::= "=" | <OP>"="
<EXPRESSION> ::= <NUM>";" | <VARIABLE>";" | <NUM><OP><EXPRESSION>
<EXPRESSION> ::= <VARIABLE><OP><EXPRESSION>
<PFIX> 	     ::= "++" | "--"
<NUM> 	     ::= [0-9]{[0-9]}
<VARIABLE>   ::= [a-z,A-Z]{[0-9,a-z,A-Z]}
<OP> 	     ::= [+-*/]
*/

void line(Assignment *a);
void expression(Assignment *a);
void semi(Assignment *a);
void pfix(Assignment *a);
void right(Assignment *a);
void assign(Assignment *a);
void var(Assignment *a);

int main(void)
{


   Assignment a;
   int i, k = 0;

   do{
      a.j = 0;
      k++;
      printf("Enter Expression : ");
      i = scanf("%s", &a.p[0]);
      if(i == 1){
         line(&a);
         printf("Parsed OK\n");   
      }
   }while(i==1);

   return 0;


}

void line(Assignment *a)
{

   if(isalpha(a->p[a->j])){
      var(a);
      right(a);
   }
   else{
      pfix(a);
      var(a);
      semi(a);
   }

   if(a->p[a->j] != '\0'){
      fprintf(stderr, "ERROR - Last letter was a '%c' ?\n", a->p[a->j]);
      exit(2);
   }

}

void semi(Assignment *a)
{

   if(a->p[a->j] != ';'){
      fprintf(stderr, "No semi-colon ?\n");
      exit(2);
   }
   a->j = a->j + 1;

}

void pfix(Assignment *a)
{

   if(!strncmp(&a->p[a->j], "++", 2) || !strncmp(&a->p[a->j], "--", 2)){
      a->j = a->j + 2;
   }
   else{
      fprintf(stderr, "Not a post/prefix Expression ?\n");
      exit(2);
   }

}

void number(Assignment *a)
{

   if(!isdigit(a->p[a->j])){
      fprintf(stderr, "Not a number ?\n");
      exit(2);
   }
   do{
      a->j = a->j + 1;
   }while(isdigit(a->p[a->j]));

}

void operator(Assignment *a)
{

   if(a->p[a->j] == '+' || a->p[a->j] == '-' ||
      a->p[a->j] == '*' || a->p[a->j] == '/'){
      a->j = a->j + 1;
   }
   else{
      fprintf(stderr, "Not an Operator ?\n");
      exit(2);
   }

}

void expression(Assignment *a)
{

   if(isdigit(a->p[a->j])){
      number(a);
      if(a->p[a->j] != ';'){
         operator(a);
         expression(a);
      }
      else{
         a->j = a->j + 1;
      }
   }
   else{
      var(a);
      if(a->p[a->j] != ';'){
         operator(a);
         expression(a);
      }
      else{
         a->j = a->j + 1;
      }
   }

}

void assign(Assignment *a)
{

   if(a->p[a->j] == '='){
      a->j = a->j + 1;
      return;
   }
   operator(a);
   if(a->p[a->j] != '='){
      fprintf(stderr, "No assignment ?\n");
      exit(2);
   }
   a->j = a->j + 1;


}

void right(Assignment *a)
{

   if(a->p[a->j] != a->p[(a->j)+1]){
      assign(a);
      expression(a);
   }
   else{
      pfix(a);
      semi(a);
   }

}

void var(Assignment *a)
{

   if(!isalpha(a->p[a->j])){
      fprintf(stderr, "Not a variable ?\n");
      exit(2);
   }
   do{
      a->j = a->j + 1;
   }while(isalnum(a->p[a->j]));

}
