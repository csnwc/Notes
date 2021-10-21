#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp; temp=A;A=B;B=temp;}

void strrev(char* s, int n);

int main(void)
{
   char str[] = "Hello World!";
   strrev(str, strlen(str));
   printf("%s\n", str);
   return 0;
}

/* Iterative Inplace String Reverse */
void strrev(char* s, int n)
{
   for(int i=0, j=n-1; i<j; i++, j--){
       SWAP(s[i], s[j]);
   }
}
