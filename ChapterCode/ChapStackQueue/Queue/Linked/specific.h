typedef int datatype;
#define FORMATSTR "%d"
#define ELEMSIZE 20

#define QUEUETYPE "Linked"

struct dataframe {
   datatype i;
   struct dataframe* next;
};
typedef struct dataframe dataframe;

struct queue {
   /* Underlying array */
   dataframe* front;
   dataframe* end;
   int size;
};












#define DOTFILE 5000
