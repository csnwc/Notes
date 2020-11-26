#include "../General/general.h"
typedef struct coll coll;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum bool {false, true} bool;

/* Create an empty coll */
coll* coll_init(void);
/* Add element onto top */
void coll_add(coll* c, datatype i);
/* Take element out */
bool coll_remove(coll* c, datatype d);
/* Does this exist ? */
bool coll_isin(coll* c, datatype i);
/* Return size of coll */
int coll_size(coll* c);
/* Clears all space used */
bool coll_free(coll* c);
