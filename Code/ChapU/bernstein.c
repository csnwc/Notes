#include <stdio.h>

int hash(unsigned int sz, char *s);

int main(void)
{

   char str[] = "Hello World!";
   // Hash modulus 7919
   printf("%d\n", hash(7919, str));
   return 0;

}

/*
Modified Bernstein hashing
5381 & 33 are magic numbers required by the algorithm
*/
int hash(unsigned int sz, char *s)
{
   unsigned long hash = 5381;
   int c;
   while((c = (*s++))){
      hash = 33 * hash ^ c;
   }
   return (int)(hash%sz);
}
