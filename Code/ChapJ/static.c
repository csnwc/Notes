#include <stdio.h>
#include <stdlib.h>

void printstuff(void);

#define MAXLOOP 20

int main(void)
{
   int r = rand() % MAXLOOP;
   for(int i=0; i<r; i++){
      printstuff();
   }
   return 0;
}

void printstuff(void)
{
   static int cnt = 0;
   printf("You've been here %d times\n", ++cnt);
}
