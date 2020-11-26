#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MIDNIGHT 24
#define MINSPERHOUR 60
int hm2ms(int h, int m);
int difft(int h1, int m1, int h2, int m2);

int main(void)
{
     assert(difft(10,0, 11,0) == 60);
     assert(difft(10,0, 10,0) == 0);
     assert(difft(10,0, 10,59) == 59);
     return EXIT_SUCCESS;
}



int difft(int h1, int m1, int h2, int m2)
{
    int t1, t2, d;

    t1 =  hm2ms(h1, m1);
    t2 =  hm2ms(h2, m2);
    if(t1 <= t2){
       d = t2 - t1;
    }
    else{
       d = hm2ms(MIDNIGHT,0) - t1 + t2;
    }

   return d;

}

int hm2ms(int h, int m)
{
   return MINSPERHOUR*h+m;
}
