#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum bool {false,true};
typedef enum bool bool;

#define MAXSTR 100000
#define CELLS 50
#define ROWS 40

void test_all(void);
void init1d(bool a[], int sz);
char* prnt(bool a[], int sz);
bool safe1d(bool a[], int sz, int x);
int bin2int(bool a[], int sz, int x);
bool rule110(bool a[], int sz, int x);
void onerow(bool a[], bool b[], int sz);
void swappointers(bool **p1, bool **p2);

int main(void)
{


   int i;
   bool a1[CELLS], a2[CELLS];
   bool *p1=a1, *p2=a2;

   test_all();

   init1d(p1, CELLS);
   printf("%s\n", prnt(p1,CELLS));
   for(i=0; i<ROWS/2; i++){
      onerow(p1, p2, CELLS);
      printf("%s\n", prnt(p2,CELLS));
      swappointers(&p1, &p2);
   }

   return EXIT_SUCCESS;
}

void swappointers(bool **p1, bool **p2)
{
   bool *tmp;
   tmp = *p1;
   *p1 = *p2;
   *p2=tmp;
}

void init1d(bool a[], int sz)
{
   int i;

   for(i=0; i<sz; i++){
      a[i] = false;
   }
   a[sz/2] = true;

}

char* prnt(bool a[], int sz)
{

   int i;
   static char str[MAXSTR];
   assert(sz < MAXSTR);
   for(i=0; i<sz; i++){
      str[i] = (a[i] ? '#' : ' ');
   }
   str[i] = '\0';
   return str;
}

bool safe1d(bool a[], int sz, int x)
{

   if(x < 0){
      return false;
   }
   if(x >= sz){
      return false;
   }
   return a[x];
}

int bin2int(bool a[], int sz, int x)
{
   return 4*safe1d(a,sz,x-1) + 2*safe1d(a,sz,x)+ 1*safe1d(a,sz,x+1);
}

bool rule110(bool a[], int sz, int x)
{
   int b[] = {false, true, true, true, false, true, true, false};
   int n = bin2int(a,sz,x);
   return b[n];
}

void onerow(bool a[], bool b[], int sz)
{

   int i;
   for(i=0; i<sz; i++){ 
      b[i] = rule110(a,sz,i);
    }
}

void test_all(void)
{

   bool a[5];
   bool b[5];
   init1d(a, 5);
   assert(strcmp(prnt(a,5), "  #  ")==0);
   assert(safe1d(a,5,0)==false);
   assert(safe1d(a,5,2)==true);
   assert(safe1d(a,5,-1)==false);
   assert(safe1d(a,5,5)==false);
   assert(safe1d(a,5,100000)==false);
   assert(bin2int(a,5,0)==0);
   assert(bin2int(a,5,1)==1);
   assert(bin2int(a,5,2)==2);
   assert(bin2int(a,5,3)==4);
   assert(bin2int(a,5,4)==0);
   assert(bin2int(a,5,4000)==0);
   assert(rule110(a,5,0)==false);
   assert(rule110(a,5,1)==true);
   assert(rule110(a,5,2)==true);
   assert(rule110(a,5,3)==false);
   assert(rule110(a,5,4)==false);
   onerow(a,b,5);
   assert(strcmp(prnt(b,5), " ##  ")==0);
}
