#include <stdio.h>
#include <stdlib.h>

int main(void)
{

   int i, j, k, n;
   char str[3000][5];
   char tmp[5];
   FILE *fp;
   int arr[3000];

   fp = fopen("34words.txt", "r");
      

   j = 0;
   do{
      i = fscanf(fp, "%s", str[j]);
      j++;
   }while(i != EOF);
   j--;

   for(i=0; i<j; i++){
      arr[i] = i;
   }

   n = 0;
   do{
      i = rand()%j;
      k = rand()%j;
      strcpy(tmp, str[i]);
      strcpy(str[i], str[k]);
      strcpy(str[k], tmp);
      n++;
   }while(n < 10000);

   for(i=0; i<j; i++){
      printf("%s\n", str[i]);
   }

}
