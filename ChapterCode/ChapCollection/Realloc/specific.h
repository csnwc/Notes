typedef int datatype;

#define COLLTYPE "Realloc"

#define FIXEDSIZE 16
#define SCALEFACTOR 2
struct coll {
   /* Underlying array */
   datatype* a;
   int size;
   int capacity;
};
