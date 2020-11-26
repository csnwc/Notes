#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp; temp=A;A=B;B=temp;}

void Reverse_String(char *s, const int n);

int main()
{

   char str[] = "Hello World!";
   
   Reverse_String(str, strlen(str)-1);
   printf("%s\n", str);
   
   return 0;
}

/* Iterative Inplace String Reverse */
void Reverse_String(char *s, const int n)
{
   int i, j;
   
   for(i=0, j=n; i<j; i++, j--)
      SWAP(s[i], s[j]);
}
