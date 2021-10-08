// This leaks - but it's not obvious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WORD 500

int main(void)
{

   char s[WORD] = "String";
   int n = strlen(s);
   /* malloc() returns a pointer to memory that
      you have access to. Note forcing cast. */
   char* t = (char*) malloc(n+1);
   // If no space, returns NULL
   assert(t != NULL);
   // Deep copy: character by character
   strcpy(t, s);
   printf("%s %s\n", s, t);
   return 0;
}
