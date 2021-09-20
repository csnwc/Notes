#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp; temp=A;A=B;B=temp;}

void Reverse_String(char *s, int start, int end);

int main(void)
{

   char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
   Reverse_String(str, 0, strlen(str)-1);
   printf("%s\n", str);
   return 0;
}

/* RECURSIVE : InLine String Reverse */
void Reverse_String(char *s, int start, int end)
{
   if(start >= end){
      return;
   }
   printf("--> %s <--\n", s);
   SWAP(s[start], s[end]);
   Reverse_String(s, start+1, end-1);
}
