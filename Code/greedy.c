#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAXVERTS 50

typedef enum {FALSE, TRUE} Boolean;

typedef struct graph{
	int cost[MAXVERTS][MAXVERTS];
	int n;
} Graph;

void distance(Graph g, int d[MAXVERTS]);

int main(void)
{

   int i;
   Graph g = {
              {{0,  5,   3,   INF, 2  },
	      {INF, 0,   2,   6,   INF},
              {INF, 1,   0,   2,   INF},
              {INF, INF, INF, 0,   INF},
              {INF, 6,   10,  4,   0 }},
              5
             };
   int d[MAXVERTS];

   distance(g, d);
   for(i=0; i<g.n; i++){
      printf("0 => %d distance %d\n", i, d[i]);
   }

   return 0;

}

void distance(Graph g, int d[MAXVERTS])
{

   Boolean final[MAXVERTS];
   int i, w, v, min;

   final[0] = TRUE;
   d[0] = 0;
   for(v=1; v<g.n; v++){
      final[v] = FALSE;
      d[v] = g.cost[0][v];
   }
   
   for(i=1; i<g.n; i++){
      min = INF;
      /* Find closest v to 0 */
      for(w=1; w<g.n; w++){
         if(!final[w]){
            if(d[w] < min){
               v = w;
               min = d[w];
            }
         }
      }
      /* Add v to S */
      final[v] = TRUE;
      /* Update remaining distances in d */
      for(w=1; w<g.n; w++){
         if(!final[w]){
            if(min + g.cost[v][w] < d[w]){
               d[w] = min + g.cost[v][w];
            }
         }
      }
   }

}
