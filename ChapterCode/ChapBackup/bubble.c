#include <stdio.h>

void bubble_sort(int b[], int s);

int main(void)
{
   int i;
   int a[] = {3, 4, 1, 2, 9, 0};
   bubble_sort(a, 6);
   for(i=0; i<6; i++){
      printf("%d ", a[i]);
   }
   printf("\n");
   return 0;
}

void bubble_sort(int b[], int s)
{

   int i, tmp;
   int changes;
   do{
      changes = 0;
      for(i=0; i<s-1; i++){
         if(b[i] > b[i+1]){
            tmp = b[i];
            b[i] = b[i+1];
            b[i+1] = tmp;
            changes++;
         }
      }
   }while(changes);
}
