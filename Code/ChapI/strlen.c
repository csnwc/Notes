#include <stdio.h>
#include <assert.h>

unsigned nstrlen(const char s[]);

int main(void)
{
   assert(nstrlen("Neill")==5);
   assert(nstrlen("")==0);
   assert(nstrlen("\n")==1);
   assert(nstrlen("abcdef")==nstrlen("fedcba"));
   return 0;
}

unsigned nstrlen(const char s[])
{
   register unsigned n = 0;
   
   while(s[n] != '\0'){
      ++n;
   }
   return n;
}
