#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXNUMTOKENS 100
#define MAXTOKENSIZE 20
#define strsame(A,B) (strcmp(A, B)==0)
#define ERROR(PHRASE) { fprintf(stderr, \
          "Fatal Error %s occurred in %s, line %d\n", PHRASE, \
          __FILE__, __LINE__); \
          exit(EXIT_FAILURE); }

struct prog{
   char wds[MAXNUMTOKENS][MAXTOKENSIZE];
   int cw; // Current Word
};
typedef struct prog Program;

void Prog(Program *p);
void Code(Program *p);
void Statement(Program *p);

int main(void)
{
   Program* prog = calloc(1, sizeof(Program));
   int i=0;
   while(scanf("%s", prog->wds[i++])==1 && i<MAXNUMTOKENS);
   assert(i<MAXNUMTOKENS);
   Prog(prog);
   printf("Parsed OK\n");
   return 0;
}

void Prog(Program *p)
{
   if(!strsame(p->wds[p->cw], "BEGIN")){
      ERROR("No BEGIN statement ?");
   }
   p->cw = p->cw + 1;
   Code(p);
}

void Code(Program *p)
{
   if(strsame(p->wds[p->cw], "END")){
      return;
   }
   Statement(p);
   p->cw = p->cw + 1;
   Code(p);
}

void Statement(Program *p)
{
   if(strsame(p->wds[p->cw], "ONE")){
      return;
   }
   if(strsame(p->wds[p->cw], "NOUGHT")){
      return;
   }
   ERROR("Expecting a ONE or NOUGHT ?");
}
