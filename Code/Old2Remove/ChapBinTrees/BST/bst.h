#include "../General/general.h"
typedef struct stack stack;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef enum bool {false, true} bool;

bst* bst_init(void);

/* Insert 1 item into the tree */
bool bst_insert(bst* b, datatype d);

/* Return number of datatypes in tree */
int bst_size(bst* b);

/* Whether the data d is stored in the tree */
bool bst_isin(bst* b, datatype d);

/* Bulk insert n items from an array a into an initialised tree */
bool bst_insertarray(bst* b, datatype* a, int n);

/* Clear all memory associated with tree, & set pointer to NULL */
bool bst_free(bst* b);
