#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp; temp=A;A=B;B=temp;}

void strrev(char* s, int start, int end);

int main(void)
{
   char str[] = "Hello World!";
   strrev(str, 0, strlen(str)-1);
   printf("%s\n", str);
   return 0;
}

/* Recursive : Inplace String Reverse */
void strrev(char* s, int start, int end)
{
   if(start >= end){
      return;
   }
   SWAP(s[start], s[end]);
   strrev(s, start+1, end-1);
}
