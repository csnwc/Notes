/* Count lowercase letters */

#include <stdio.h>
#include <ctype.h>

int main(void)
{

   int c, i, letter[26];

   /* zero */
   for (i = 0; i < 26; ++i){
      letter[i] = 0;
   }
   /* count */
   while ((c = getchar())!=EOF){
      if(islower(c)){
         ++letter[c - 'a'];
      }
   }
   /* results */
   for (i = 0; i < 26; ++i){
      if (i % 5 == 0){
         printf("\n");
      }
      printf("%c:%4d ", 'a' + i, letter[i]);
   }
   printf("\n\n");
   return 0;
}

