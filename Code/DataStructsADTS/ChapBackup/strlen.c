#include <stdio.h>

unsigned nstrlen(const char *s);

int main(void)
{
   char s[] = "Neill";
   printf("%d\n", nstrlen(s));
   return 0;
}

unsigned nstrlen(const char *s)
{
   register int n = 0;
   for(; *s != '\0'; ++s)
      ++n;
   return n;
}
