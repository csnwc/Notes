#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_NUM_NODES 100000
#define BOARD 3

struct tile2d{
   char tile[BOARD][BOARD];
   int spacex,spacey;
} ;

struct tilelist{
   char str[MAX_NUM_NODES][BOARD*BOARD+1];
   int n;
};

struct tile1d {
   char str[BOARD*BOARD+1];
   int spacex,spacey;
} ;

typedef struct tile2d Tile2D;
typedef struct tile1d Tile1D;
typedef struct tilelist TileList;

void tile1dto2d(Tile2D *t, Tile1D *st);
void tile2dto1d(Tile1D *st, Tile2D *t);
void tilecpy(Tile2D *d, Tile2D *s);
void print2dtile(Tile2D *t);
int solvable(Tile2D *t, TileList *l, int d, int m);
void tilecpy(Tile2D *d, Tile2D *s);

void main(void)
{

   int m;
   Tile2D init;
   TileList tl;

   Tile1D t1 = {{"258413 76"}, 0, 2};
   tile1dto2d(&init, &t1);

   for(m=2; m<20; m++){
      tl.n = 0;
      if(solvable(&init, &tl, 1, m)){
         printf("Solved in %d\n", m);
         break;
      }
      else{
         printf("Can't solve it in %d\n", m);
      }
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
   printf("---\n");

}

int solvable(Tile2D *t, TileList *list, int d, int m)
{

   Tile1D s;
   Tile2D nt;

   if(d > m) return 0;

   tile2dto1d(&s, t);
   if(strcmp(s.str, "12345678 ") == 0){
      return 1;
   }

   if(t->spacex < (BOARD-1)){ /* Move Space Right */
      tilecpy(&nt, t);
      nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey][nt.spacex+1];
      nt.tile[nt.spacey][nt.spacex+1] = ' ';
      nt.spacex = nt.spacex + 1;
      if(solvable(&nt, list, d+1, m)){
         print2dtile(&nt);
         return 1;
      }
   }

   if(t->spacey < (BOARD-1)){ /* Move Space Down */
      tilecpy(&nt, t);
      nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey+1][nt.spacex];
      nt.tile[nt.spacey+1][nt.spacex] = ' ';
      nt.spacey = nt.spacey + 1;
      if(solvable(&nt, list, d+1, m)){
         print2dtile(&nt);
         return 1;
      }
   }


   if(t->spacey > 0){ /* Move Space Up */
      tilecpy(&nt, t);
      nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey-1][nt.spacex];
      nt.tile[nt.spacey-1][nt.spacex] = ' ';
      nt.spacey = nt.spacey - 1;
      if(solvable(&nt, list, d+1, m)){
         print2dtile(&nt);
         return 1;
      }
   }

   if(t->spacex > 0){ /* Move Space Left */
      tilecpy(&nt, t);
      nt.tile[nt.spacey][nt.spacex] = nt.tile[nt.spacey][nt.spacex-1];
      nt.tile[nt.spacey][nt.spacex-1] = ' ';
      nt.spacex = nt.spacex - 1;
      if(solvable(&nt, list, d+1, m)){
         print2dtile(&nt);
         return 1;
      }
   }

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
      
}
