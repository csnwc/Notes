/* Nested Structures */

#include <stdio.h>

struct date {
   short day;
   short month;
   short year;
};

struct person {
   char name[25];
   struct date date;
};

void print_person_copy(struct person p);
void print_person_point(struct person *p);

int main(void)
{
   struct person k;
   printf("Enter your surname : ");
   scanf("%s", k.name);
   printf("Enter your Birthday: ");
   scanf("%hi/%hi/%hi", &k.date.day,
         &k.date.month, &k.date.year);
   print_person_copy(k);
   print_person_point(&k);
   return 0;
}

void print_person_copy(struct person p)
{
   printf("Name \"%s\", Born %02i/%02i/%i\n",
       p.name, p.date.day,
       p.date.month, p.date.year);
}

void print_person_point(struct person *p)
{
   printf("Name \"%s\", Born %02hi/%02hi/%hi\n",
      p->name, p->date.day,
      p->date.month, p->date.year);
}
