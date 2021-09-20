#include "../General/general.h"
typedef struct stack stack;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef enum bool {false, true} bool;

/* Create an empty stack */
stack* stack_init(void);
/* Add element to top */
void stack_push(stack* s, datatype i);
/* Take element from top */
bool stack_pop(stack* s, datatype* d);
/* Clears all space used */
bool stack_free(stack* s);

/* Optional? */

/* Copy top element into d (but don't pop it) */
bool stack_peek(stack*s,  datatype* d);
/* Make a string version - keep .dot in mind */
void stack_tostring(stack*, char* str);























/* Output a picture in the GraphViz/.dot format */
void stack_todot(stack*, char* fname);
