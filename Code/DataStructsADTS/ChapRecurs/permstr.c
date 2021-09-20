#include <stdio.h>
#include <string.h>

void swap(char* x, char* y);
void permute(char* a, int lf, int rt);
 
int main()
{
    char str[] = "ABCD";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}

void permute(char* s, int lf, int rt)
{
   int i;
   if (lf == rt){
     printf("%s\n", s);
   }
   else
   {
       for (i = lf; i <= rt; i++)
       {
          swap(&s[lf], &s[i]);
          permute(s, lf+1, rt);
          swap(&s[lf], &s[i]); /* Backtrack */
       }
   }
}









void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
