#include "specific.h"
#include "queue.h"

#ifndef BOUNDED
   #define LOOPTEST 10000
#else
   #define LOOPTEST BOUNDED
#endif

int main(void)
{

   int i;
   char str[1000];
   datatype d;
   queue* q;

   printf("Basic Queue (%s) Tests ... Start\n", QUEUETYPE);

   queue_tostring(NULL, str); assert(strcmp(str, "")==0);
   q = queue_init();
   assert(q != NULL);
   assert(queue_size(q) == 0);
   queue_tostring(q, str); assert(strcmp(str, "")==0);

   queue_enqueue(q, 10);
   assert(queue_size(q) == 1);
   queue_tostring(q, str); assert(strcmp(str, "10")==0);
   assert(queue_dequeue(q, &d));
   assert(d == 10);
   assert(queue_size(q) == 0);

   queue_enqueue(q, 20);
   assert(queue_size(q) == 1);
   queue_tostring(q, str); assert(strcmp(str, "20")==0);
   queue_enqueue(q, 30);
   queue_enqueue(q, 40);
   queue_enqueue(q, 50);
   queue_tostring(q, str); assert(strcmp(str, "20|30|40|50")==0);
   queue_todot(q, "q.dot");
   assert(queue_dequeue(q, &d));
   assert(d == 20);
   assert(queue_size(q) == 3);
   assert(queue_dequeue(q, &d));
   assert(queue_dequeue(q, &d));
   assert(queue_dequeue(q, &d));
   assert(queue_size(q) == 0);

   for(i=1; i<LOOPTEST/2; i++){
      queue_enqueue(q,i);
      assert(queue_size(q) == i);
   }
   for(i=1; i<LOOPTEST/2; i++){
      assert(queue_dequeue(q, &d));
      assert(queue_size(q) == LOOPTEST/2-i-1);
   }
   for(i=1; i<LOOPTEST; i++){
      queue_enqueue(q,i);
      assert(queue_dequeue(q, &d));
      assert(d==i);
   }
   assert(queue_size(q) == 0);

   assert(queue_free(q));
   printf("Basic Queue Tests ... Stop\n");

   return 0;

}
