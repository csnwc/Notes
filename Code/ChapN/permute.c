// From e.g.  http://www.geeksforgeeks.org
#include <stdio.h>
#include <string.h>

#define SWAP(A,B) {char temp = *A; *A = *B; *B = temp;}

void permute(char *a, int s, int e);

int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}

void permute(char *a, int s, int e)
{
   if (s == e){
     printf("%s\n", a);
     return;
   }
   for (int i = s; i <= e; i++){
      SWAP((a+s), (a+i)); // Bring one char to the front
      permute(a, s+1, e);
      SWAP((a+s), (a+i)); // Backtrack
   }
}
