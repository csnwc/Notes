#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stackelem{
	int i;
	struct staclelem *prev;
};

typedef struct stackelem Elem;

struct thestack{
   Elem *tp;
};

typedef struct thestack Stack;
	
void StringReverse(char *s);
void InitialiseStack(Stack *s);
void Push(Stack *s, int n);
int Pop(Stack *s);

int main(void)
{

   char str[] = "Hello World";
   StringReverse(str);
   printf("%s\n", str);
   return 0;

}

void StringReverse(char *str)
{

   char *k;
   int i;
   int l = 0;
   Stack s;

   InitialiseStack(&s);
   k = str;
   while(*k != '\0'){
      Push(&s, (int)*k);
      k++;
      l++;
   }

   k = str;
   for(i=0; i<l; i++){
      *k = Pop(&s);
      k++;
   }
}
