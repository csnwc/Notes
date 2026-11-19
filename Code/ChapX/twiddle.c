#include <stdio.h>
#include <assert.h>
#include <stdint.h>

int main(void)
{

#ifdef BITWISE
   printf("Bitwise Logic\n");
#else
   printf("No Bitwise Logic\n");
#endif

   for(long l=0; l<2048l*1024l*1024l; l++){
      uint32_t i = 1024*1024;
      uint32_t j = 0x5a;
      #ifdef BITWISE 
         i = i >> 1;
         j = j & 0x7;
      #else
         i = i / 2;
         j = j%8;
      #endif
   }
}
