#include "students.h"

int failures(struct student *j, int n)
{
   int i, cnt = 0;
   for(i=0; i<n; i++){
      cnt += (tolower(j->grade) == 'f');
      j++;
   }
   return cnt;
}
