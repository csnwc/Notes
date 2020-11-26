#define MAX_QUEUE 100

struct queue{
        char n[MAX_QUEUE];
        int front;
        int back;
};
typedef struct queue Queue;

void InitialiseQueue(Queue *q);
char RemoveQueue(Queue *q);
void InsertQueue(char c, Queue *q);
int EmptyQueue(Queue q);
