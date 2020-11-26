#include <stdio.h>
#include <math.h>

#define MAX_ITERS	100
#define STARTY	 	-1.5
#define ENDY		1.5
#define STARTX		-1.5
#define ENDX		1.5
#define YSTEP		((ENDY - STARTY)/19.0)
#define XSTEP		((ENDX - STARTX)/50.0)

struct complex{
	double r;
	double i;
};

typedef struct complex Complex;

Complex ComplexMinus(Complex a, Complex b);
Complex  ComplexMult(Complex a, Complex b);
double GetMag(Complex a);
int Converging(double x, double y);

int main(void)
{

   int i;
   double x, y;
   char symbol[] = ".?#";

   for(y=STARTY; y<=ENDY; y+=YSTEP){
      for(x=STARTX; x<=ENDX; x+=XSTEP){
         i = Converging(x, y) ;
         putchar(symbol[i*2/MAX_ITERS]);
      }
      printf("\n");
   }

   return 0;

}

int Converging(double x, double y)
{

   int k;
   Complex z;
   Complex a;
   Complex c;
   double d;

   c.r = x;
   c.i = y;
   z.r = 0.0;
   z.i = 0.0;

   for(k=0; k<MAX_ITERS; k++){
      a = ComplexMult(z, z);
      z = ComplexMinus(a, c);
      d = GetMag(z);
      if(d > 1.0){
         return k;
      }
   }

   return k;

}

Complex ComplexMinus(Complex a, Complex b)
{

   Complex r;

   r.r = a.r - b.r;
   r.i = a.i - b.i;

   return r;

}

Complex ComplexMult(Complex a, Complex b)
{

   Complex r;
   r.r = a.r*b.r - a.i*b.i;
   r.i = a.r*b.i + a.i*b.r;

   return r;

}

double GetMag(Complex a)
{

   return sqrt(a.r * a.r + a.i * a.i);

}
