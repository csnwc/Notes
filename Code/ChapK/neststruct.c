#include <stdio.h>

struct dateofbirth {
   unsigned char day;
   unsigned short month;
   unsigned short year;
};
typedef struct dateofbirth dob;

typedef struct {
   char* name;
   dob date;
} person;

void print_byval(person b);
void print_byref(const person* p);

int main(void)
{
   person a = {"Gary", {17, 5, 1999}};
   print_byval(a);
   print_byref(&a);
}

void print_byval(person b)
{
   printf("%s %hhu/%hi/%hi\n", b.name, b.date.day, b.date.month, b.date.year); 
}

void print_byref(const person* p)
{
   printf("%s %hhu/%hi/%hi\n", p->name, p->date.day, p->date.month, p->date.year); 
}
