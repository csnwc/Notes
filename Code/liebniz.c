#include <stdio.h>
#include <stdlib.h>

typedef long double pitype;

int main(void)
{

   pitype i;
   pitype d = 0.0;
   int cnt = 0;
   pitype sgn = 1.0;

   for(i=1.; i<100000000000.; i+=2.){
      d += sgn*4.0/i;
      sgn *= -1.0;
      cnt++;
      if(cnt%100000000==0){
        cnt = 0;
        printf("%12.0Lf %12.9Lf\n", i/2.0, d);
      }
   }

   return EXIT_SUCCESS;
}
