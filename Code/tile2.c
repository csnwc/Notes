#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_NUM_NODES 400000
#define BOARD 3

struct tile2d{
   char tile[BOARD][BOARD];
   int spacex,spacey;
   int gen;
   struct tile2d *parent;
} ;

struct tilequeue{
   struct tile2d *tile;
   int st;
   int nd;
};

struct tile1d {
   char str[BOARD*BOARD+1];
   int spacex,spacey;
} ;

typedef struct tile2d Tile2D;
typedef struct tile1d Tile1D;
typedef struct tilequeue TileQueue;

int IsInQueue(Tile2D *t, TileQueue *q);
void InitQueue(TileQueue *q);
void tile1dto2d(Tile2D *t, Tile1D *st);
void tile2dto1d(Tile1D *st, Tile2D *t);
void tilecpy(Tile2D *d, Tile2D *s);
void print2dtile(Tile2D *t);
int solvable(TileQueue *queue);
void tilecpy(Tile2D *d, Tile2D *s);
int PopTile(Tile2D *t, TileQueue *q);
void PushTile(Tile2D *t, TileQueue *q);
void printAllBoards(Tile2D *t);

void main(void)
{

   Tile2D init;
   TileQueue tq;

   Tile1D t1 = {{"258431 67"}, 0, 2};
   tile1dto2d(&init, &t1);
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

void tile1dto2d(Tile2D *t, Tile1D *st)
{

   int i;
   char *p;
   char *s;

   s = st->str;
   p  = (char *)t->tile;
   for(i=0; i<BOARD*BOARD; i++)
      *p++ = *s++;
   t->spacex = st->spacex;
   t->spacey = st->spacey;

}

void tile2dto1d(Tile1D *st, Tile2D *t)
{

   int i;
   char *p;
   char *s;

   s = st->str;
   p  = (char *)t->tile;
   for(i=0; i<BOARD*BOARD; i++)
      *s++ = *p++;
   *s = '\0';
   st->spacex = t->spacex;
   st->spacey = t->spacey;

}

void print2dtile(Tile2D *t)
{

   int i, j;

   for(j=0; j<BOARD; j++){
      for(i=0; i<BOARD; i++){
         printf("%c", t->tile[j][i]);
      }
      printf("\n");
   }
   printf("Level %d\n---\n", t->gen);

}

int solvable(TileQueue *queue)
{

   Tile1D s;
   Tile2D nt;
   Tile2D t;

   while(PopTile(&t, queue)){
   
      tile2dto1d(&s, &t);
      if(strcmp(s.str, "12345678 ")==0){
         printf("Yes! Level %d\n", t.gen);
         printAllBoards(&t);
         return 1;
      }
   
      if(t.spacex < (BOARD-1)){ /* Move Space Right */
         tilecpy(&nt, &t);
         nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey][nt.spacex+1];
         nt.tile[nt.spacey][nt.spacex+1] = ' ';
         nt.spacex = nt.spacex + 1;
         nt.gen = nt.gen+ 1;
         nt.parent = &queue->tile[queue->st-1];
         PushTile(&nt, queue);
      }
   
      if(t.spacey < (BOARD-1)){ /* Move Space Down */
         tilecpy(&nt, &t);
         nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey+1][nt.spacex];
         nt.tile[nt.spacey+1][nt.spacex] = ' ';
         nt.spacey = nt.spacey + 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         PushTile(&nt, queue);
      }
   
   
      if(t.spacey > 0){ /* Move Space Up */
         tilecpy(&nt, &t);
         nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey-1][nt.spacex];
         nt.tile[nt.spacey-1][nt.spacex] = ' ';
         nt.spacey = nt.spacey - 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         PushTile(&nt, queue);
      }
   
      if(t.spacex > 0){ /* Move Space Left */
         tilecpy(&nt, &t);
         nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey][nt.spacex-1];
         nt.tile[nt.spacey][nt.spacex-1] = ' ';
         nt.spacex = nt.spacex - 1;
         nt.gen = nt.gen + 1;
         nt.parent = &queue->tile[queue->st-1];
         PushTile(&nt, queue);
      }

   };

   return 0;

}

void tilecpy(Tile2D *d, Tile2D *s)
{

   char *td, *ts;
   int i;

   td = (char *)d->tile;
   ts = (char *)s->tile;
   for(i=0; i<BOARD*BOARD; i++){
      *td++ = *ts++;
   }
   d->spacex = s->spacex;
   d->spacey = s->spacey;
   d->gen = s->gen;
   d->parent = s->parent;
      
}

int PopTile(Tile2D *t, TileQueue *q)
{

  if(q->nd != q->st){
     tilecpy(t, &q->tile[q->st]);
     q->st = q->st + 1;
     /*printf("Queue Start %d\n", q->st);*/
     return 1;
  }
  return 0;

}

int IsInQueue(Tile2D *t, TileQueue *q)
{

   int i;

   for(i=0; i<q->nd; i++){
      if(strncmp((char *)t->tile, (char *)&q->tile[i], 9)==0){
         return 1;
      }
   }
   return 0; 

}

void PushTile(Tile2D *t, TileQueue *q)
{
   if(!IsInQueue(t, q)){
      tilecpy(&q->tile[q->nd], t);
      q->nd = q->nd + 1;
      if((q->nd % 5000) == 0) printf("Queue End %d (%d)\n", q->nd, t->gen);
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
