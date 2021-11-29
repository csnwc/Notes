#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int *src, int *spare, int l, int r);
void merge(int *src, int *spare, int l, int m, int r);

#define NUM 5000

int main(void)
{
   int a[NUM];
   int spare[NUM];

   for(int i=0; i<NUM; i++){
      a[i] = rand()%100;
   }

   mergesort(a, spare, 0, NUM-1);

   for(int i=0; i<NUM; i++){
      printf("%4d => %d\n", i, a[i]);
   }

   return 0;
}

void mergesort(int *src, int *spare, int l, int r)
{
   int m = (l+r)/2;
   if(l != r){
      mergesort(src, spare, l, m);
      mergesort(src, spare, m+1, r);
      merge(src, spare, l, m, r);
   }
}

void merge(int *src, int *spare, int l, int m, int r)
{
   int s1 = l;
   int s2 = m+1;
   int d = l;

   do{
      if(src[s1] < src[s2]){
         spare[d++] = src[s1++];
      }
      else{
         spare[d++] = src[s2++];
      }
   }while((s1 <= m) && (s2 <= r));

   if(s1 > m){
      memcpy(&spare[d], &src[s2], sizeof(spare[0])*(r-s2+1));
   }
   else{
      memcpy(&spare[d], &src[s1], sizeof(spare[0])*(m-s1+1));
   }
   memcpy(&src[l], &spare[l], (r-l+1)*sizeof(spare[0]));
}
