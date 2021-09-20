typedef int datatype;

#define COLLTYPE "Fixed"

#define FIXEDSIZE 5000
struct coll {
   /* Underlying array */
   datatype a[FIXEDSIZE];
   int size;
};
