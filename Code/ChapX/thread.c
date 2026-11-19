#include <stdio.h>
#include <omp.h>

int main() {
   printf("Num Cores/threads = %d\n", omp_get_num_procs());
   #pragma omp parallel
   {
       int id = omp_get_thread_num();
       printf("Hello from thread %d\n", id);
   }
   printf("\n");
   return 0;
}
