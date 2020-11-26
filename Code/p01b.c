/* 
<PROG>       ::= "BEGIN" <CODE>
<CODE>       ::= "END" | <STATEMENT> <CODE>
<STATEMENT>  ::= "ONE" | "NOUGHT"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXNUMTOKENS 100
#define MAXTOKENSIZE 7
#define PROGNAME "01.no"
#define strsame(A,B) (strcmp(A, B)==0)
#define ERROR(PHRASE) {
printf("Fatal Error : %s occured in %s at Line %d\n",
PHRASE, __FILE__, __LINE__);exit(2);}

struct prog{
   char words[MAXNUMTOKENS][MAXTOKENSIZE];
   int cw; /* Current Word */
};
typedef struct prog Program;

void Prog(Program *p);
void Code(Program *p);
void Statement(Program *p);

int main(void)
{
   int i;
   FILE *fp;
   Program prog;

   prog.cw = 0;
   for(i=0; i<MAXNUMTOKENS; i++)
      prog.words[i][0] = '\0';
   if(!(fp = fopen(PROGNAME, "r"))){
      printf("Cannot open %s\n", PROGNAME);
      exit(2);
   }
   i=0;
   while(fscanf(fp, "%s", prog.words[i++])==1 && i<MAXNUMTOKENS);
   assert(i<MAXNUMTOKENS);
   Prog(&prog);
   printf("Parsed OK\n");
   return 0;
}


void Prog(Program *p)
{
   if(!strsame(p->words[p->cw], "BEGIN"))
      ERROR("No BEGIN statement ?");
   p->cw = p->cw + 1;
   Code(p);
}

void Code(Program *p)
{
   if(strsame(p->words[p->cw], "END"))
      return;
   Statement(p);
   p->cw = p->cw + 1;
   Code(p);
}

void Statement(Program *p)
{
   if(strsame(p->words[p->cw], "ONE")){
      printf("1\n");
      return;
   }
   if(strsame(p->words[p->cw], "NOUGHT")){
      printf("0\n");
      return;
   }
   ERROR("I was expecting a ONE or NOUGHT ?");
}
