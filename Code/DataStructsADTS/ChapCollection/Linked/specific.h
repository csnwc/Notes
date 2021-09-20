typedef int datatype;

#define COLLTYPE "Linked"

struct dataframe {
   datatype i;
   struct dataframe* next;
};
typedef struct dataframe dataframe;

struct coll {
   /* Underlying array */
   dataframe* start;
   int size;
};
