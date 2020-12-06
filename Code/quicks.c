#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void quicksort(int *a, int l, int r);
int partition (int arr[], int low, int high);
void sorted(int*a);
int intcompare(const void *a, const void *b);

#define NUM 2500000

int main(void)
{

   int i;
   static int a[NUM]; 

#ifdef RAND
   /* Random */
   printf("Random ");
   for(i=0; i<NUM; i++){
      a[i] = rand()%10000;
   }
#endif
#ifdef SORT
   /* Pathologically sorted */
   printf("Sorted ");
   for(i=0; i<NUM; i++){
      a[i] = i;
   }
#endif
#ifndef BUILTIN
   printf("quicksort()\n");
   quicksort(a, 0, NUM-1);
#else
   printf("qsort()\n");
   qsort(a, NUM, sizeof(int), intcompare);
#endif
   sorted(a);

   return 0;
}

void sorted(int* a)
{
   int i;
   for(i=0; i<NUM-1; i++){
      assert(a[i] <= a[i+1]);
   }
}

void quicksort(int *a, int l, int r)
{

   int pivpoint;
   
   pivpoint = partition(a, l, r);
   if(l < pivpoint) quicksort(a, l, pivpoint-1);
   if(r > pivpoint) quicksort(a, pivpoint+1, r);

}

int partition(int *a, int l, int r)
{

   int piv;

   piv = a[(l+r)/2];
   while(l<r){
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

int intcompare(const void *a, const void *b)
{
   const int *ia = (const int *)a;
   const int *ib = (const int *)b;
   return *ia - *ib;
}
