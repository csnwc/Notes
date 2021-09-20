#include <stdio.h>

int main(void)
{
   int inches, feet, fathoms;
   fathoms = 7;
   feet = 6 * fathoms;
   inches = 12 * feet;
   printf("Wreck of the Hesperus:\n");
   printf("Its depth at sea in");
   printf(" different units:\n");
   printf(" %d fathoms\n", fathoms);
   printf(" %d feet\n", feet);
   printf(" %d inches\n", inches);
   return 0;
}
