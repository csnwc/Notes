#include <stdio.h>
#include <string.h>

#define NOTFOUND -1
#define NUMPEOPLE 6

struct person{
	char *name;
        int age;
};

typedef struct person Person;

int FindAge(char *name, Person *p, int n);

int main(void)
{
   Person ppl[NUMPEOPLE] = {
              {"Ackerby", 21}, {"Bloggs", 25},
              {"Chumley", 26}, {"Dalton",   25},
              {"Eggson", 22}, {"Fulton",  41} };

   printf("%d\n", FindAge("Eggson",   ppl, NUMPEOPLE));
   printf("%d\n", FindAge("Campbell", ppl, NUMPEOPLE));

   return 0;
}

int FindAge(char *name, Person *p, int n)
{
   int j;
   for(j=0; j<n; j++){
      if(strcmp(name, p[j].name) == 0){
         return p[j].age;
      }
   }

   return NOTFOUND;
}
