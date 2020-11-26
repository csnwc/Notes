#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int isprime(int n);
int isvowel(int c);
void test_all(void);
int alphacode(int c);
int planetbob(char a, char b, char c);

int main(void)
{
  char a, b;
  test_all();

  for(a='a'; a<'z'; a++){
     for(b='a'; b<'z'; b++){
        if(planetbob(a,b,a)){
           printf("%c%c%c\n", a, b, a);
        }
     }
  }
  return EXIT_SUCCESS;
}

void test_all(void)
{

   assert(isvowel('a'));
   assert(isvowel('e'));
   assert(isvowel('i'));
   assert(isvowel('o'));
   assert(isvowel('u'));
   assert(!isvowel('b'));
   assert(isvowel('A'));
   assert(isvowel('E'));
   assert(isvowel('I'));
   assert(isvowel('O'));
   assert(isvowel('U'));
   assert(!isvowel('B'));

   assert(isprime(-1)==0);
   assert(isprime(0)==0);
   assert(isprime(1)==0);
   assert(isprime(2)==1);
   assert(isprime(3)==1);
   assert(isprime(9)==0);
   assert(isprime(97)==1);
   assert(isprime(144)==0);

   assert(alphacode('a')==1);
   assert(alphacode('f')==6);
   assert(alphacode('z')==26);
   assert(alphacode('A')==1);
   assert(alphacode('F')==6);
   assert(alphacode('Z')==26);

   assert(planetbob('b', 'o', 'b') == 1);
   assert(planetbob('a', 'a', 'b') == 0);
   assert(planetbob('a', 'o', 'b') == 0);
   assert(planetbob('B', 'O', 'B') == 1);
   assert(planetbob('A', 'A', 'B') == 0);
   assert(planetbob('A', 'O', 'B') == 0);

}

int planetbob(char a, char b, char c)
{

   int sum;
   if(isvowel(a) == isvowel(b)){
      return 0;
   }
   if(a != c){
      return 0;
   }
   sum = alphacode(a) + alphacode(b) + alphacode(c);
   if(!isprime(sum)){
      return 0;
   }
   return 1;
}

int alphacode(int d)
{
   int c = tolower(d);
   return c - 'a' + 1;
}

int isprime(int n)
{
  int i;
  if(n < 2){
    return 0;
  }
  for(i=2; i<=n/2; i++){
    if((n%i)==0){
      return 0;
    }
  }
  return 1;
}

int isvowel(int d)
{
  int c = tolower(d);
  switch(c){
     case 'a':
     case 'e':
     case 'i':
     case 'o':
     case 'u':
        return 1;
  }
  return 0;
}
