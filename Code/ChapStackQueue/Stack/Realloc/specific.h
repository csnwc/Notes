typedef int datatype;
#define FORMATSTR "%d"
#define ELEMSIZE 20

#define STACKTYPE "Realloc"

#define FIXEDSIZE 16
#define SCALEFACTOR 2

struct stack {
   /* Underlying array */
   datatype* a;
   int size;
   int capacity;
};
