typedef int datatype;
#define FORMATSTR "%d"
#define ELEMSIZE 20
#define STACKTYPE "Linked"

struct dataframe {
   datatype i;
   struct dataframe* next;
};
typedef struct dataframe dataframe;

struct stack {
   /* Underlying array */
   dataframe* start;
   int size;
};
