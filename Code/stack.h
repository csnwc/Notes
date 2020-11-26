#define STACKSIZE 200

struct stackelem{
        char i;
};

typedef struct stackelem Elem;

struct thestack{
   Elem stk[STACKSIZE];
   int top;
};

typedef struct thestack Stack;
void InitialiseStack(Stack *s);
void Push(Stack *s, char c);
char Pop(Stack *s);
int EmptyStack(Stack *s);
