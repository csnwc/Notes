#include <stdio.h>

#define NUM_POSS_SCORES 62
#define OUTSHOT(S) (((S%2==0 && S>=2 && S<=40) || S==50)?1:0)

int finishes(int n, int d);
int remap(int s);

void main(void)
{
   if(finishes(287, 5) == 0){
      printf("Not possible\n");
   }
}

/* Is there an outshot of score n, in d darts ? */
int finishes(int n, int d)
{

   int i, j, flag;

   if(n <= 0) return 0;
   if(d==1)
      if(OUTSHOT(n)){
         printf("3:%d ", n);
         return 1;
      }
      else
         return 0;

   flag = 0;
   for(i=0; i<NUM_POSS_SCORES; i++){
      j = remap(i);
      if(finishes(n-j, d-1)){
         printf("%d:%d ", 4-d, j);
         if(d==3) printf("\n");
         flag=1;
      }
   }

   return flag;

}

int remap(int s)
{
   int k[] = {1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
	     11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	      2,  4,  6,  8, 10, 12, 14, 16, 18, 20,
	     22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
	      3,  6,  9, 12, 15, 18, 21, 24, 27, 30,
	     33, 36, 39, 42, 45, 48, 51, 54, 57, 60,
	     25, 50};			
   return k[s];
}

/* Results
3:40 2:60 3:50 2:50 1:51 
3:40 2:57 1:54 
3:40 2:54 3:34 2:60 1:57 
3:40 2:51 3:34 2:57 1:60 
3:50 2:51 1:50 
*/
