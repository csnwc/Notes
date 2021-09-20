#include <stdio.h>
#include <ctype.h>

int main(void)
{
   char w1[100] = "test";
   char *w2 = "test";

   printf("%s -> ", w1);
   w1[0] = toupper(w1[0]);
   printf("%s\n", w1);

   printf("%s -> ", w2);
   w2[0] = toupper(w2[0]);
   printf("%s\n", w2);

   return 0;
}
