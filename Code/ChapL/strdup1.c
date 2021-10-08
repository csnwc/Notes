// This code is not allowed by the -Wvla flag
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WORD 500

int main(void)
{

   char s[WORD] = "String";
   int n = strlen(s) + 1;
   char t[n];
   // Deep copy: character by character
   strcpy(t, s);
   printf("%s %s\n", s, t);
   return 0;
}
