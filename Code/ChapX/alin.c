#include <stdio.h>
#include <stddef.h>

struct nrm {
   char i;
   float j;
   short k;
};

// Could also use #pragma pack(1)
struct pkd { 
   char i;
   float j;
   short k;
} __attribute__((packed));

int main()
{
   struct nrm s;
   struct pkd t;

   printf("%zu  ", offsetof(struct nrm, i));
   printf("%zu  ", offsetof(struct nrm, j));
   printf("%zu\t= %zu\n", offsetof(struct nrm, k), sizeof(s));

   printf("%zu  ", offsetof(struct pkd, i));
   printf("%zu  ", offsetof(struct pkd, j));
   printf("%zu\t= %zu\n\n", offsetof(struct pkd, k), sizeof(t));
}
