#include <stdio.h>
#include <string.h>


#define Q 33554393
#define D 26
#define index(C) (C-'A')


int rk(char *p, char *a);


int main(void)
{
   printf("%d\n", rk("LOT", "SLOT"));
   return 0;
}


int rk(char *p, char *a)
{


   int i, dM = 1, h1=0, h2=0;
   int m = strlen(p);
   int n = strlen(a);
   for(i=1; i<m; i++) dM = (D*dM)%Q;
   for(i=0; i<m; i++){
      h1 = (h1*D+index(p[i]))%Q;
      h2 = (h2*D+index(a[i]))%Q;
   }
   /* h1 = substring hash */
   /* h2 = master hash */
   for(i=0; h1!=h2; i++){
      h2 = (h2+D*Q-index(a[i])*dM) % Q;
      h2 = (h2*D+index(a[i+m])) % Q;
      if(i>n-m) return n;
   }
   return i;
     


}
