#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "/usr/openwin/include/pixrect/rasterfile.h"

#define MAXWORDS 1000
#define BIGGESTWORD 30
#define MAXVARNAME BIGGESTWORD
#define STACKSIZE 50
#define PI 3.141517

struct stack {
	char s[STACKSIZE][BIGGESTWORD];
	int fp;
};

struct turtle {
	double x;
	double y;
	double orient;
};

struct variable {
	char name[MAXVARNAME];
	double val;
        struct variable *next;
};

struct prog {
	int nws; /* Number fo Words */
	int cw;  /* Current Word being interpretted */
        char *words[MAXWORDS]; /* Array of pointers to words */
	char filename[200];
        struct variable headv; /* List of Valid Variables */
	struct stack stack;
        struct turtle tl;
};

typedef struct prog ProgInfo;

unsigned char globalimg[512][768];

/* ----- Grammar Definition -----

<main>		-> "{" <body>
<body>		-> <decvar> <instrctlst>
<decvar>	-> "VARS" <varlist>
<varlist>	-> <var><varlist> | ";"
<varnum>	-> [0-9]<digits> | <var>
<var>		-> <letter><alphnum>
<digits>	-> '.'<digits> | [0-9]<digits> | NULL
<alphanum>	-> [A-Z,0-9]<alphanum> | NULL
<instrctlst>	-> <instruction><instrctlst> | "}"
<instruction>	-> <fd> | <lt> | <rt> | <do> | <set>
<fd>		-> "FD" <varnum> ";"
<lt>		-> "LT" <varnum> ";"
<rt>		-> "RT" <varnum> ";"
<do>		-> "DO" <var> "FROM" <varnum> "TO" <varnum> "{" <instrclst>
<set>		-> "SET" <var> ":=" <polish>
<polish>	-> "+"<polish> | "-"<polish> | "*"<polish> | "/"<polish> | <varnum><polish> | ";"

*/

void eprintf(char *fmt,...);
void ReadFile(ProgInfo *p);
void Push(char *w, struct stack *st);
void PrintStack(struct stack *st);
void parse_digits(char *c);
double parse_varnum(struct variable *v, char *c);
void parse_instruction(ProgInfo *p);
void parse_instrctlst(ProgInfo *p);
void parse_alphanum(char *c);
void parse_var(char *c);
void parse_varlist(ProgInfo *p);
void parse_decvars(ProgInfo *p);
void parse_body(ProgInfo *p);
void parse_main(ProgInfo *p);
void inc(ProgInfo *p);
int strsame(char *s, char *b);
void parse_assign(ProgInfo *p);
void parse_polish(ProgInfo *p);
void parse_FD(ProgInfo *p);
void parse_LT(ProgInfo *p);
void parse_RT(ProgInfo *p);
void parse_set(ProgInfo *p);
void parse_DO(ProgInfo *p);
void BlankVariable(struct variable *v);
void AddVariable(struct variable *v, char *w);
double ValidVar(struct variable *p, char *w);
void do_forwards(ProgInfo *p, double d);
void do_turn(ProgInfo *p, double d);
void Write_Raster(char *name);

	
int main()
{

   ProgInfo pi;

   strcpy(pi.filename, "prog.ttl");
   pi.nws = 0;
   pi.cw = 0;
   pi.stack.fp = 0;
   pi.tl.x = 384.0;
   pi.tl.y = 256.0;
   pi.tl.orient = 0.0;
   BlankVariable(&pi.headv);

   ReadFile(&pi);

   parse_main(&pi);
   printf("Parsed OK\n");
   Write_Raster("doof.ras");

   return 0;

}

int strsame(char *s, char *b)
{

   /*printf("strsame(%s, %s) ? ", s, b);*/
   if(strcmp(s, b) == 0){
      /*printf("Yes\n");*/
      return 1;
   }
   else{
      /*printf("No\n");*/
      return 0;
   }

}

void Push(char *w, struct stack *st)
{

   strcpy(st->s[st->fp], w);
   st->fp++;
   if(st->fp >= STACKSIZE){
      eprintf("Stack Overflow\n");
   }

}

void Pop(struct stack *st, char *w)
{

   st->fp--;
   if(st->fp < 0){
      eprintf("Stack Underflow\n");
   }
   strcpy(w, st->s[st->fp]);

}


void PrintStack(struct stack *st)
{

   int i;

   printf("STACK : ");
   for(i=0; i<st->fp; i++){
      printf("%s ", st->s[i]);
   }
   printf("\n");

}

void EvaluateStack(ProgInfo *p)
{



   exit(2);

}


void eprintf(char *fmt,...)
{

  va_list args;
  va_start(args, fmt);

  vfprintf(stderr, fmt, args);
  va_end(args);
  exit(2);

}

void ReadFile(ProgInfo *p)
{

   FILE *fp;
   char temp[BIGGESTWORD];
   int n, m;
   int j;

   fp = fopen(p->filename, "r");
   if(!fp){
      eprintf("Failed to open %s\n", p->filename);
   }

   n = 0;
   do{
      j = fscanf(fp, "%s", temp);
      if(j==1){
         m = strlen(temp);
         if(m > 0){
            p->words[n] = calloc(m+1, sizeof(char));
            strcpy(p->words[n], temp);
            n++;
         }
      }
   }while(j==1);
   printf("\n");

   fclose(fp);
   p->nws = n;

}

void inc(ProgInfo *p) 
{

   p->cw++;
   /*printf("Incremented to Word %d\n", p->cw);*/
   if(p->cw >= p->nws){
      eprintf("Parse Error\n");
   }

}

void parse_main(ProgInfo *p)
{

   p->cw = 0;
   if(!strsame("{", p->words[p->cw])){
      eprintf("I Was Expecting a { symbol\n");
   }
   inc(p);
   parse_body(p);

   if(p->cw != (p->nws-1)){
      eprintf("Parse error before end\n");
   }

   return;

}

void parse_body(ProgInfo *p)
{

   /*printf("In parse_body(%d)\n", p->cw);*/
   parse_decvars(p);
   parse_instrctlst(p);

}

void parse_decvars(ProgInfo *p)
{

   /*printf("In parse_decvars(%d)\n", p->cw);*/
   if(strsame("VARS", p->words[p->cw])){
      inc(p);
      parse_varlist(p);
   }

   return;

}

void BlankVariable(struct variable *v)
{

   strcpy(v->name, "");
   v->val = 0.0;
   v->next = NULL;

}

void SetVariable(struct variable *v, char *w, double d)
{

   while(v->next != NULL){
      if(strsame(v->name, w)){
         v->val = d;
         return;
      }
      v = v->next;
   }

   eprintf("Variable \"%s\" undefined.\n", w);
   return;

}

double ValidVar(struct variable *v, char *w)
{

   while(v->next != NULL){
      if(strsame(v->name, w)){
         return v->val;
      }
      v = v->next;
   }

   eprintf("Variable \"%s\" undefined.\n", w);
   return 0.0;

}

void AddVariable(struct variable *v, char *w)
{

   while(v->next != NULL){
      if(strsame(v->name, w)){
         eprintf("I've got two variables called \"%s\"\n", w);
      }
      v = v->next;
   }

   v->next = calloc(1, sizeof(struct variable));
   BlankVariable(v->next);
   strcpy(v->name, w);

}

void parse_varlist(ProgInfo *p)
{


   /*printf("In parse_varlist(%d)\n", p->cw);*/
   if(strsame(";", p->words[p->cw])){
      inc(p);
      return;
   }

   parse_var(p->words[p->cw]);
   AddVariable(&p->headv, p->words[p->cw]);
   inc(p);
   parse_varlist(p);

}

void parse_var(char *c)
{

   /*printf("In parse_var(%c)\n", *c);*/
   if(!isupper(*c)){
      eprintf("Was expecting an upper-case letter variable\n");
   }
   else{
      parse_alphanum(c+1);
   }

}

void parse_alphanum(char *c)
{

   /*printf("In parse_alphanum(%c)\n", *c);*/
   if(*c == '\0') return;

   if(!isupper(*c) && !isdigit(*c)){
      eprintf("Was expecting a letter or an upper-case letter\n");
   }
   parse_alphanum(c+1);

}

void parse_instrctlst(ProgInfo *p)
{

   /*printf("In parse_instrctlst(%d)\n", p->cw);*/
   if(strsame("}", p->words[p->cw])){
      return;
   }
   else{
      parse_instruction(p);
      inc(p);
      parse_instrctlst(p);
   }

}

void do_turn(ProgInfo *p, double d)
{

   printf("Orient = %f %f\n", p->tl.orient, p->tl.orient*360.0/2.0/PI);
   p->tl.orient += (d*2.0*PI/360.0);
   while(p->tl.orient > 2.0*PI)
      p->tl.orient -= 2.0*PI;
   while(p->tl.orient < -2.0*PI)
      p->tl.orient += 2.0*PI;
   printf("Orient = %f %f\n", p->tl.orient, p->tl.orient*360.0/2.0/PI);

}

void do_forwards(ProgInfo *p, double d)
{


   int i;

   for(i=0; i<(int)d; i++){
      p->tl.x += sin(p->tl.orient);
      p->tl.y -= cos(p->tl.orient);
      if(p->tl.x >= 0.0 && p->tl.x < 768.0 && p->tl.y > 0.0 && p->tl.y < 512.0){
         globalimg[(int)(p->tl.y)][(int)(p->tl.x)] = 255;
      }
   }

}

void parse_FD(ProgInfo *p)
{

   double d;

   inc(p);
   d = parse_varnum(&p->headv, p->words[p->cw]);
   do_forwards(p, d);
   inc(p);
   if(!strsame(";", p->words[p->cw])){
      eprintf("I was expecting a \";\"\n");
   }
 
}

void parse_RT(ProgInfo *p)
{

   double d;

   inc(p);
   d = parse_varnum(&p->headv, p->words[p->cw]);
   printf("Going right %f\n", d);
   do_turn(p, d);
   inc(p);
   if(!strsame(";", p->words[p->cw])){
      eprintf("I was expecting a \";\"\n");
   }

}

void parse_LT(ProgInfo *p)
{

   double d;

   inc(p);
   d = parse_varnum(&p->headv, p->words[p->cw]);
   printf("Going left %f\n", d);
   do_turn(p, -d);
   inc(p);
   if(!strsame(";", p->words[p->cw])){
      eprintf("I was expecting a \";\"\n");
   }

}

void parse_DO(ProgInfo *p)
{

   double from;
   int jump;
   char vname[MAXVARNAME];
   char test[MAXVARNAME];
   double d, e;

   inc(p);
   parse_var(p->words[p->cw]);
   ValidVar(&p->headv, p->words[p->cw]);
   strcpy(vname, p->words[p->cw]);
   inc(p);
   if(!strsame("FROM", p->words[p->cw])){
      eprintf("I was expecting a \"FROM\" symbol\n");
   }
   inc(p);
   from = parse_varnum(&p->headv, p->words[p->cw]);
   SetVariable(&p->headv, vname, from);
   inc(p);
   if(!strsame("TO", p->words[p->cw])){
      eprintf("I was expecting a \"TO\" symbol\n");
   }
   inc(p);
   strcpy(test, p->words[p->cw]);
   inc(p);
   if(!strsame("{", p->words[p->cw])){
      eprintf("I was expecting a \"{\" symbol\n");
   }
   inc(p);
   jump = p->cw;
   do{
      parse_instrctlst(p);
      d = ValidVar(&p->headv, vname);
      d += 1.0;
      SetVariable(&p->headv, vname, d);
      e = parse_varnum(&p->headv, test);
      if(d <= e){
         p->cw = jump;
      }
   }while(d <= e);

}

void parse_instruction(ProgInfo *p)
{

   if(strsame("FD", p->words[p->cw])){
      parse_FD(p);
   }
   else{
      if(strsame("RT", p->words[p->cw])){
         parse_RT(p);
      }
      else{
         if(strsame("LT", p->words[p->cw])){
            parse_LT(p);
         }
         else{
            if(strsame("SET", p->words[p->cw])){
               parse_set(p);
            }
            else{
               if(strsame("DO", p->words[p->cw])){
                  parse_DO(p);
               }
               else{
                  eprintf("I was expecting \"FD\", \"LT\", \"SET\", \"DO\" or \"RT\"\n");
               }
            }
         }
      }
   }

}

double parse_varnum(struct variable *v, char *c)
{

   if(isdigit(*c)){
      parse_digits(c+1);
      return atof(c);
   }
   else{
      parse_var(c);
      return ValidVar(v, c);
   }

}

void parse_digits(char *c)
{

   /*printf("In parse_digits(%c)\n", *c);*/
   if(*c == '\0'){
      return;
   }
   if(!isdigit(*c) && *c != '.'){
      eprintf("I was expecting a digit\n");
   }
   parse_digits(c+1);

}

void parse_set(ProgInfo *p)
{

   char vname[BIGGESTWORD];
   char w[BIGGESTWORD];

   inc(p);
   parse_var(&p->words[p->cw][0]);
   ValidVar(&p->headv, p->words[p->cw]);
   strcpy(vname, p->words[p->cw]);
   inc(p);
   if(!strsame(":=", p->words[p->cw])){
      eprintf("I was expecting a \":=\" symbol\n");
   }
   inc(p);
   parse_polish(p);

   Pop(&p->stack, w);
   if(p->stack.fp != 0){
      eprintf("Stack still has items on it ?\n");
   }
   SetVariable(&p->headv, vname, atof(w));
   printf("%s = %f\n", vname, atof(w));

}

void parse_polish(ProgInfo *p)
{

   char a[BIGGESTWORD];
   char b[BIGGESTWORD];
   char w[BIGGESTWORD];
   double x, y;
   char c;

   if(strsame(";", p->words[p->cw])){
      return;
   }

   strcpy(w, p->words[p->cw]);
   if(strsame("+", w) || strsame("-", w) || strsame("*", w) || strsame("/", w)){
      c = p->words[p->cw][0];
      Pop(&p->stack, a);
      Pop(&p->stack, b);
      x = parse_varnum(&p->headv, a);
      y = parse_varnum(&p->headv, b);
      switch(c){
         case '+' : sprintf(w, "%f", y+x);
                    break;
         case '-' : sprintf(w, "%f", y-x);
                    break;
         case '*' : sprintf(w, "%f", y*x);
                    break;
         case '/' : sprintf(w, "%f", y/x);
                    break;
      }
      Push(w, &p->stack);
   }
   else{
      parse_varnum(&p->headv, p->words[p->cw]);
      Push(p->words[p->cw], &p->stack);
   }

   inc(p);
   parse_polish(p);

}

void parse_vno(ProgInfo *p)
{

   if(strsame("+", p->words[p->cw])){
      return;
   }
   if(strsame("-", p->words[p->cw])){
      return;
   }
   if(isdigit(p->words[p->cw][0])){
      parse_digits(&p->words[p->cw][1]);
   }
   else{
      parse_var(p->words[p->cw]);
   }

}

void Write_Raster(char *name)
{

   FILE *fp;
   struct rasterfile rast;

   fp = fopen(name, "wb");
   if(!fp){
      eprintf("Cannot Write to %s\n", name);
   }

   rast.ras_magic = RAS_MAGIC;
   rast.ras_width = 768;
   rast.ras_height = 512;
   rast.ras_depth = 8;
   rast.ras_length = 768*512;
   rast.ras_type = 1;
   rast.ras_maptype = RMT_NONE;
   rast.ras_maplength = 0;
   if(fwrite(&rast, sizeof(rast), 1, fp) != 1){
      eprintf("Cannot Write Raster Header %s\n", name);
   }
   if(fwrite(globalimg, 768, 512, fp) != 512){
      eprintf("Cannot Write Raster %s\n", name);
   }
   fclose(fp);

}
