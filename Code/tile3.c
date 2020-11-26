#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_NUM_NODES 400000
#define BOARD 3

struct tile2d{
   int tile;
   int spacex,spacey;
   int gen;
   struct tile2d *parent;
} ;

struct tilequeue{
   struct tile2d *tile;
   int st;
   int nd;
};

typedef struct tile2d Tile2D;
typedef struct tilequeue TileQueue;

int IsInQueue(Tile2D *t, TileQueue *q);
void InitQueue(TileQueue *q);
void tilecpy(Tile2D *d, Tile2D *s);
void print2dtile(Tile2D *t);
int solvable(TileQueue *queue);
int PopTile(Tile2D *t, TileQueue *q);
void PushTile(Tile2D *t, TileQueue *q);
void printAllBoards(Tile2D *t);
void Make2DfromInt(char b[BOARD][BOARD], int n);
void MakeIntfrom2D(int *n, char b[BOARD][BOARD]);

void main(void)
{

   Tile2D init;
   TileQueue tq;

   init.spacex = 0;
   init.spacey = 2;
   init.tile = 258431067;
   init.gen = 1;
   init.parent = NULL;

   InitQueue(&tq);
   PushTile(&init, &tq);

   if(solvable(&tq)){
      printf("Solved\n");
   }
   else{
      printf("Can't solve it\n");
   }
      


}

void print2dtile(Tile2D *t)
{

   int j;
   char str[20];

   sprintf(str, "%09d", t->tile);
   for(j=0; j<BOARD*BOARD; j++){
      putchar(str[j]);
      if(j%BOARD == (BOARD-1)) putchar('\n');
   }
   printf("Level %d\n---\n", t->gen);

}

int solvable(TileQueue *queue)
{

   Tile2D nt;
   Tile2D t;
   char brd[3][3];

   while(PopTile(&t, queue)){
   
      if(t.tile == 123456780){
         printf("Yes! Level %d\n", t.gen);
         printAllBoards(&t);
         return 1;
      }
   

/*
      Make2DfromInt(brd, t.tile);
{int i,j;
         for(j=0; j<3; j++){for(i=0; i<3; i++){ printf("%c", brd[j][i]);}
         printf("\n");}
}
*/

      if(t.spacex < (BOARD-1)){ /* Move Space Right */
         Make2DfromInt(brd, t.tile);
         tilecpy(&nt, &t);
         brd[nt.spacey][nt.spacex] = brd[nt.spacey][nt.spacex+1];
         brd[nt.spacey][nt.spacex+1] = '0';
         nt.spacex = nt.spacex + 1;
         nt.gen = nt.gen+ 1;
         nt.parent = &queue->tile[queue->st-1];
         MakeIntfrom2D(&nt.tile, brd);
         PushTile(&nt, queue);
      }
   
      if(t.spacey < (BOARD-1)){ /* Move Space Down */
         Make2DfromInt(brd, t.tile);
         tilecpy(&nt, &t);
         brd[nt.spacey][nt.spacex] = brd[nt.spacey+1][nt.spacex];
         brd[nt.spacey+1][nt.spacex] = '0';
         nt.spacey = nt.spacey + 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         MakeIntfrom2D(&nt.tile, brd);
         PushTile(&nt, queue);
      }
   
   
      if(t.spacey > 0){ /* Move Space Up */
         Make2DfromInt(brd, t.tile);
         tilecpy(&nt, &t);
         brd[nt.spacey][nt.spacex] = brd[nt.spacey-1][nt.spacex];
         brd[nt.spacey-1][nt.spacex] = '0';
         nt.spacey = nt.spacey - 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         MakeIntfrom2D(&nt.tile, brd);
         PushTile(&nt, queue);
      }
   
      if(t.spacex > 0){ /* Move Space Left */
         Make2DfromInt(brd, t.tile);
         tilecpy(&nt, &t);
         brd[nt.spacey][nt.spacex] = brd[nt.spacey][nt.spacex-1];
         brd[nt.spacey][nt.spacex-1] = '0';
         nt.spacex = nt.spacex - 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         MakeIntfrom2D(&nt.tile, brd);
         PushTile(&nt, queue);
      }

   }

   return 0;

}

void tilecpy(Tile2D *d, Tile2D *s)
{
   memcpy(d, s, sizeof(Tile2D));
}

int PopTile(Tile2D *t, TileQueue *q)
{

  if(q->nd != q->st){
     tilecpy(t, &q->tile[q->st]);
     q->st = q->st + 1;
     return 1;
  }
  return 0;

}

int IsInQueue(Tile2D *t, TileQueue *q)
{

   int i;
   Tile2D *p;
   int n;

   p = &q->tile[0];
   n = t->tile;
   for(i=0; i<q->nd; i++, p++){
      if(n == p->tile){
         return 1;
      }
   }
   return 0; 

}

void PushTile(Tile2D *t, TileQueue *q)
{

   if(!IsInQueue(t, q)){
      /*printf("%09d\n", t->tile);*/
      tilecpy(&q->tile[q->nd], t);
      q->nd = q->nd + 1;
      if((q->nd % 1000) == 0) printf("Queue End %d (%d)\n", q->nd, t->gen);
   }
}

void InitQueue(TileQueue *q)
{

   q->tile = malloc(sizeof(Tile2D)*MAX_NUM_NODES);
   if(q->tile == NULL){
      fprintf(stderr, "Cannot Malloc\n");
      exit(2);
   }
   q->st = 0;
   q->nd = 0;

}

void printAllBoards(Tile2D *t)
{
   if(t == NULL) return;
   print2dtile(t);
   printAllBoards(t->parent);
}

void Make2DfromInt(char b[BOARD][BOARD], int n)
{
   char str[20];
   int i;

   sprintf(str, "%09d", n);
   memcpy(b, str, BOARD*BOARD);
}

void MakeIntfrom2D(int *n, char b[BOARD][BOARD])
{

   char str[20];
   int i;

   memcpy(str, b, 9);
   str[9] = '\0';
   *n = atoi(str);
}
