#include <stdio.h>
#include <stdlib.h>

#define BY 5
#define BX 5
#define MAXBOARDS 200000
#define P 'O'
#define H ' '
#define F 'X'

struct board {
   char brd[BY][BX];
   int parent;
   int hash;
};

struct state{
   int cb;
   int top;
   struct board list[MAXBOARDS];
};

void init_state(struct state *s);
void addboard(char b[BY][BX], int prnt, struct state *s);
void boardcpy(char dst[BY][BX], char src[BY][BX]);
void print_state(struct state *s);
void peg_left(struct state *s);
void peg_right(struct state *s);
void peg_down(struct state *s);
void peg_up(struct state *s);
void all_moves(struct state *s);
int complete_board(struct state *s, int b);
void any_dupes(struct state *s);
void print_solution(struct state *s, int n);
void print_board(struct state *s, int i);
int ncmp(char a[BY][BX], char b[BY][BX]);
int hash(char b[BY][BX]);



int main(void)
{

   static struct state st;
   init_state(&st);
   do{
      all_moves(&st);
/*
      print_state(&st);
*/
      if(st.cb%100==0) printf("%d %d\n", st.top, st.cb);
   }while(1);
   return 0;
}

void any_dupes(struct state *s)
{

   int i, j;

   for(j=0; j<s->top; j++){
      for(i=j+1; i<s->top; i++){
         if(memcmp(s->list[j].brd, s->list[i].brd, BX*BY)==0){
            printf("Board %d == %d\n", i, j);
         }
      }
   }

}

void init_state(struct state *s)
{

   char ibrd[BY][BX] =	{
			{P,P,H,P,P},
			{H,P,P,P,H},
			{P,P,H,P,P},
			{P,P,P,P,P},
			{H,H,P,H,H}
			};
/*
   char ibrd[BY][BX] =	{
			{H,H,P,H,H},
			{H,H,P,H,H},
			{P,P,H,P,P},
			{H,H,P,H,H},
			{H,H,P,H,H},
			};
   char ibrd[BY][BX] =	{
			{F,P,P,P,F},
			{H,P,P,P,H},
			{H,H,P,H,P},
			{H,P,P,P,P},
			{F,H,P,P,F},
			};
*/
/*
   char ibrd[BY][BX] =	{
			{F,P,P,H,F},
			{H,P,P,P,P},
			{P,P,P,P,P},
			{P,P,P,P,H},
			{F,H,P,P,F},
			};
*/
/*
   char ibrd[BY][BX] =	{
			{F,F,F,P,P,P,F,F,F},
			{F,F,F,P,P,P,F,F,F},
			{F,F,F,P,P,P,F,F,F},
			{P,P,P,P,P,P,P,P,P},
			{P,P,P,P,H,P,P,P,P},
			{P,P,P,P,P,P,P,P,P},
			{F,F,F,P,P,P,F,F,F},
			{F,F,F,P,P,P,F,F,F},
			{F,F,F,P,P,P,F,F,F},
			};
*/
/*
   char ibrd[BY][BX] =	{
			{H,P,P,H,H},
			{P,P,H,P,H},
			{H,H,H,P,P},
			{P,P,P,P,H},
			{P,P,H,P,H}
			};
*/
/*
  char ibrd[BY][BX] =	{
			{P,P,H,P,P},
			{P,P,P,P,H},
			{H,P,P,P,P},
			{P,H,P,P,P},
			{H,H,H,H,H}
			};
*/
   s->cb = 0;
   addboard(ibrd, 0, s);

   s->list[0].hash = hash(ibrd);
}

int hash(char b[BY][BX])
{

   int x, y;
   int f = 0;
   int tcnt = 0;
   int fcnt = 0;
   int pc = 0;
   int sm = 0;
   char *p = &b[0][0];
   for(y=0; y<BY; y++){
      for(x=0; x<BX; x++){
         if(*p == P) pc += (x+y);
         if(*p++ == P){
            if(f) tcnt+=x;
            else fcnt+=x;
         }
         f = !f;
      }
   }
   sm = tcnt*1000000+pc*1000+fcnt;

   if(b[BY/2][BX/2] == P)   sm += 100000000;
   if(b[BY/2+1][BX/2] == P) sm += 200000000;
   if(b[BY/2-1][BX/2] == P) sm += 400000000;
   if(b[BY/2][BX/2-1] == P) sm += 800000000;
   if(b[BY/2][BX/2+1] == P) sm += 1600000000;
   return sm;

}

void boardcpy(char dst[BY][BX], char src[BY][BX])
{
   memcpy(dst, src, BX*BY);
}

void all_moves(struct state *s)
{
   peg_left(s);
   peg_right(s);
   peg_up(s);
   peg_down(s);
   s->cb = s->cb + 1;
   if(s->cb >= s->top){
      fprintf(stderr, "Can't do it ?\n");
      exit(2);
   }
}

void peg_left(struct state *s)
{

   char ob[BY][BX];
   char nb[BY][BX];
   int i, j;

   boardcpy(ob, s->list[s->cb].brd);
   for(j=0; j<BY; j++){
      for(i=2; i<BX; i++){
         if(ob[j][i] == P && ob[j][i-1] == P && ob[j][i-2] == H){
             boardcpy(nb, ob);
             nb[j][i-2] = P;
             nb[j][i-1] = H;
             nb[j][i  ] = H;
             addboard(nb, s->cb, s);
         }
      }
   }

}

void peg_up(struct state *s)
{

   char ob[BY][BX];
   char nb[BY][BX];
   int i, j;

   boardcpy(ob, s->list[s->cb].brd);
   for(j=2; j<BY; j++){
      for(i=0; i<BX; i++){
         if(ob[j][i] == P && ob[j-1][i] == P && ob[j-2][i] == H){
             boardcpy(nb, ob);
             nb[j-2][i] = P;
             nb[j-1][i] = H;
             nb[j  ][i] = H;
             addboard(nb, s->cb, s);
         }
      }
   }

}


void peg_right(struct state *s)
{

   char ob[BY][BX];
   char nb[BY][BX];
   int i, j;

   boardcpy(ob, s->list[s->cb].brd);
   for(j=0; j<BY; j++){
      for(i=0; i<BX-2; i++){
         if(ob[j][i] == P && ob[j][i+1] == P && ob[j][i+2] == H){
             boardcpy(nb, ob);
             nb[j][i+2] = P;
             nb[j][i+1] = H;
             nb[j][i  ] = H;
             addboard(nb, s->cb, s);
         }
      }
   }

}

void peg_down(struct state *s)
{

   char ob[BY][BX];
   char nb[BY][BX];
   int i, j;

   boardcpy(ob, s->list[s->cb].brd);
   for(j=0; j<BY-2; j++){
      for(i=0; i<BX; i++){
         if(ob[j][i] == P && ob[j+1][i] == P && ob[j+2][i] == H){
             boardcpy(nb, ob);
             nb[j+2][i] = P;
             nb[j+1][i] = H;
             nb[j  ][i] = H;
             addboard(nb, s->cb, s);
         }
      }
   }

}



int ncmp(char a[BY][BX], char b[BY][BX])
{

   int i;
   char *p, *q;

   p = &a[0][0];
   q = &b[0][0];
   for(i=0; i<BX*BY; i++){
      if(*p++ != *q++) return 0;
   }
   return 1;

}

void addboard(char b[BY][BX], int prnt, struct state *s)
{

   int j;
   int ps;
   struct board *bd;

   ps = hash(b);
   bd = &s->list[0];
   for(j=0; j<s->top; j++){
      if(bd->hash == ps){
         if(ncmp(b, bd->brd)){
            return;
         }
      }
      bd++;
   }

   boardcpy(s->list[s->top].brd, b);
   s->list[s->top].parent = prnt;
   s->list[s->top].hash = ps;
   if(complete_board(s, s->top)){
      fprintf(stderr, "Found it , board %d\n", s->top);
      print_solution(s, s->top);
      exit(2);
   }
   s->top = s->top + 1;
   if(s->top >= MAXBOARDS){
      fprintf(stderr, "Too many boards !\n");
      exit(2);
   }

}

void print_solution(struct state *s, int n)
{

   do{
      print_board(s, n);
      n = s->list[n].parent;
   }while(n != 0);

}

int complete_board(struct state *s, int b)
{

   int i, j;

   for(j=0; j<BY; j++){
      for(i=0; i<BY; i++){
         if(j==BY/2 && i==BX/2){
           if(s->list[b].brd[j][i] != P) return 0;
         }
         else{
            if(s->list[b].brd[j][i] == P) return 0;
         }
      }
   }
   return 1;

}

void print_board(struct state *s, int i)
{

   int x, y;
   printf("+");
   for(x=0; x<BX; x++){
      printf("-");
   }
   printf("+\n");
   for(y=0; y<BY; y++){
      printf("|");
      for(x=0; x<BX; x++){
          printf("%c", s->list[i].brd[y][x]);
      }
      printf("|");
      if(y==BY/2) printf(" prnt=%6d, hash=%2d", s->list[i].parent, s->list[i].hash);
      printf("\n");
   }
   printf("+");
   for(x=0; x<BX; x++){
      printf("-");
   }
   printf("+\n\n");

}

void print_state(struct state *s)
{

   int i;

   printf("Current = %d\n", s->cb);
   printf("Top     = %d\n", s->top);
   for(i=0; i<s->top; i++){
      print_board(s, i);
   }

}
