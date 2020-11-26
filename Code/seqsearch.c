#include <stdio.h>
#include <strings.h>

#define NUMPEOPLE 6

struct key{
	char *name;
        int age;
};

typedef struct key Key;

int FindAge(char *name, Key *l, int n);

int main(void)
{

   Key a[NUMPEOPLE] = {
              {"Ackerby", 21}, {"Bloggs", 25}, {"Chumley", 26},
              {"Dalton",   25}, {"Eggson", 22}, {"Fulton",  41} };

   printf("%d\n", FindAge("Eggson",   a, NUMPEOPLE));
   printf("%d\n", FindAge("Campbell", a, NUMPEOPLE));

   return 0;

}

int FindAge(char *name, Key *l, int n)
{

   int j;

   for(j=0; j<n; j++){
      if(strcmp(name, l[j].name) == 0){
         return l[j].age;
      }
   }

   return -1;

}
