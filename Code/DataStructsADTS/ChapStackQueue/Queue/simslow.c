#include "specific.h"
#include "queue.h"
#include "time.h"

int main(void)
{
   queue* q;
   datatype d;
   char str[1000];

   srand(time(NULL));
   q = queue_init();
   while(queue_size(q) < 10){
      /* Slow output */
      if(rand()%10 < 1){
         queue_dequeue(q, &d);
      }
      /* Faster input */
      if(rand()%10 < 3){
         d = rand()%1000;
         queue_enqueue(q, d);
      }
      queue_tostring(q, str);
      printf("Queue : %s\n", str);
   }
         
   queue_free(q);
   return 0;
}
