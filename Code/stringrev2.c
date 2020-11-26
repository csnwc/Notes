#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp; temp=A;A=B;B=temp;}

void Reverse_String(char *s, int start, int end);

int main(void)
{

   char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
   Reverse_String(str, 0, strlen(str)-1);
   printf("%s\n", str);
   
}

/* RECURSIVE : InLine String Reverse */
void Reverse_String(char *s, int start, int end)
{

   if(start < end){
	   /* Debugging Info */
	   printf("Reverse String -->%s<--\n", s);
      /* Here's where all the work is done */
      SWAP(s[start], s[end]);
      Reverse_String(s, start+1, end-1);
   }

}
