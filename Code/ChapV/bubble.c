#include <stdio.h>
#include <stdbool.h>

#define SWAP(A, B) {int t; t=A; A=B; B=t;}
#define NUMS 6

void bubble_sort(int b[], int s);

int main(void)
{
   int a[] = {3, 4, 1, 2, 9, 0};
   bubble_sort(a, NUMS);
   for(int i=0; i<NUMS; i++){
      printf("%i ", a[i]);
   }
   printf("\n");
   return 0;
}

void bubble_sort(int b[], int s)
{
   bool changes;
   do{
      changes = false;
      for(int i=0; i<s-1; i++){
         if(b[i] > b[i+1]){
            SWAP(b[i], b[i+1]);
            changes = true;
         }
      }
   }while(changes);
}
