#include <stdio.h>

int isin(int k, int *a, int n);

int main(void)
{

   int a[] = {4,7,19,25,36,37,50,100,101,205,220,271,301,321};

   if(isin(205, a, 14) > 0) printf("Found It !\n");
   else printf("Not in List\n");

   return 0;

}

int isin(int k, int *a, int n)
{

   int l, r, m;

   l = 0;
   r = n - 1;

   while(l <= r){

      m = (l+r)/2;
      if(k == a[m])
         return m;
      else{
         if (k > a[m])
            l = m + 1;
         else
            r = m- 1;
      }

   }

   return -1;
         
}
