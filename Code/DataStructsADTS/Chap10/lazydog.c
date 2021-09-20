#include <stdio.h>
#include <ctype.h>

int main(void)
{
   char s[100] = "The Quick Brown Fox Leaps" \
                 "Over the Lazy Dog";
   short used[26] = {0};
   char c;
   int i = 0;
   while(s[i]){
      c = tolower(s[i]);
      if(islower(c)){
         used[c - 'a'] = 1;
      }
      i++;
   }
   for(i=0; i<26; i++){
      if(!used[i]){
         printf("%c has not been used.\n", i+'a');
      }
   }
   return 0;
}
