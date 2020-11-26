#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

enum bool {false, true};
typedef enum bool bool;

bool isin(int a[], int s, int n);
void test_all(void);
void fill_array(int a[], int size);
void print_array(int a[], int size);

#define MAXSONGS 100000000

int main(void)
{

   static int a[MAXSONGS];
   int size = 100000;

   srand(time(NULL));

   test_all();
   fill_array(a, size);
/*
   print_array(a, size);
*/
   return EXIT_SUCCESS;
}

void print_array(int a[], int size)
{
   int i;
   for(i=0; i<size; i++){
      printf("%3d", a[i]+1);
   }
   printf("\n");
}

void fill_array(int a[], int size)
{

   int i, n;
   a[0] = rand()%size;
   for(i=1; i<size; i++){
      do{
         n = rand()%size;
      }while(isin(a,i,n));
      a[i] = n;
   }

}

void test_all(void)
{

   int a[10] = {1,2,5,6};
   assert(!isin(a,0,10000));
   assert(isin(a, 4, 1));
   assert(isin(a, 4, 2));
   assert(isin(a, 4, 5));
   assert(isin(a, 4, 6));
   assert(!isin(a, 4, -1));
   assert(!isin(a, 4, 8));
   assert(!isin(a, 4, 3));
   assert(!isin(a, 4, 4));

   fill_array(a, 10);
   assert(!isin(&a[1], 9, a[0]));
   assert(!isin(&a[0], 9, a[9]));
   assert(isin(&a[0], 10, 0));
   assert(isin(&a[0], 10, 4));

}

bool isin(int a[], int s, int n)
{

   int i;
   if(s < 1){
      return false;
   }
   for(i=0; i<s; i++){
      if(a[i] == n){
         return true;
      }
   }
   return false;
}
