#include "students.h"

int failures(struct student j[], int n);

int main(void)
{
   struct student class[] = {
      {"Bloggs", 95112174, 'c'},
      {"Doobeedoo", 96162578, 'b'},
      {"Campbell", 96112103, 'f'},
      {"Johnson", 96185617, 'a'}
   };
   printf("Number of fails : %d\n",
   failures(class, 4));
   return 0;
}
