// A FAILED attempt to
// convert all 'n' chars to 'N'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void nify(char s[]);

int main(void)
{

   nify("neill");
   return 0;

}

// In-Place : Swaps all 'n' -> 'N'
void nify(char s[])
{
   for(int i=0; s[i]; i++){
      if(s[i] == 'n'){
         s[i] = 'N';
      }  
   }
}
