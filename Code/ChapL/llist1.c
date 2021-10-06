// Store a list of numbers
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct data {
   int num;
   struct data* next;
};
typedef struct data data;

int main(void)
{
   data c = {5 , NULL};
   data b = {17, &c};
   data a = {11, &b};

   // print first number
   printf("%i\n", a.num);
   data* p = &a;
   // Can also get to it via p
   printf("%i\n", p->num);
   // Pointer chasing : The Key concept
   p = p->next;
   // We're accessing b, without using it's name
   printf("%i\n", p->num);
   p = p->next;
   // And c
   printf("%i\n", p->num);

   return 0;
}
