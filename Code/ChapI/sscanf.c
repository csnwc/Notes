// Simple demo of sscanf (and fgets in passing)
#include <stdio.h>
#include <assert.h>

#define BIGSTR 1000
#define SMLSTR 100
#define DAYSINYEAR 365.2425

#include <stdio.h>

int main(void)
{


   printf("Please type your first name and your age\n");
   char bigstr[BIGSTR];
   fgets(bigstr, BIGSTR, stdin);
   char name[SMLSTR];
   int age;
   // Note no "&" before name : passed by reference already
   assert(sscanf(bigstr, "%s %d\n", name, &age)==2);
   printf("%s, you've lived approximately %.0f days\n",
          name, ((double)(age)+0.5)*DAYSINYEAR);
   return 0;

}
