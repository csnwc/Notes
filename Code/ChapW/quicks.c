#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int partition(int *a, int l, int r);
void quicksort(int *a, int l, int r);

#define NUM 100000

int main(void)
{
   int a[NUM];

   for(int i=0; i<NUM; i++){
      a[i] = rand()%100;
   }
   quicksort(a, 0, NUM-1);

   return 0;
}

void quicksort(int *a, int l, int r)
{
   int pivpoint = partition(a, l, r);
   if(l < pivpoint){
      quicksort(a, l, pivpoint-1);
   }
   if(r > pivpoint){
      quicksort(a, pivpoint+1, r);
   }
}

int partition(int *a, int l, int r)
{
   int piv = a[l];
   while(l<r){
      /* Right -> Left Scan */
      while(piv < a[r] && l<r) r--;
      if(r!=l){
         a[l] = a[r];
         l++;
      }
      /* Left -> Right Scan */
      while(piv > a[l] && l<r) l++;
      if(r!=l){
         a[r] = a[l];
         r--;
      }
   }
   a[r] = piv;
   return r;
}
