#define MAX_QUEUE 100

struct queue{
	Node *n[MAX_QUEUE];
        int front;
        int back;
};
typedef struct queue Queue;

void InitialiseQueue(Queue *q)
{

   q->front = 0;
   q->back = 0;

}

Node *Remove(Queue *q)
{

   Node *n;

   n = q->n[q->front];
   q->front = (q->front + 1)%MAX_QUEUE;

   return n;

}

void Insert(Node *t, Queue *q)
{

   q->n[q->back] = t;
   q->back = (q->back + 1)%MAX_QUEUE;

}

int Empty(Queue q)
{

   if(q.front == q.back) return 1;
   return 0;

}
