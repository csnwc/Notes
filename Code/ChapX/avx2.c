#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <immintrin.h>

#define SIZE 536870912
int main(){
    // Allocate 32-byte aligned memory for AVX (essential for performance)
    float *a = (float *)aligned_alloc(32, SIZE * sizeof(float));
    float *b = (float *)aligned_alloc(32, SIZE * sizeof(float));
    float *c = (float *)aligned_alloc(32, SIZE * sizeof(float));
    assert(a && b && c);
    // Initialize arrays
    for (int i=0; i<SIZE; i++){
        a[i] = (float)i;
        b[i] = (float)(i * 2);
    }
    // Process 8 floats at a time using AVX (256-bit registers)
    for (int i=0; i<SIZE; i+= 8){
        __m256 va = _mm256_load_ps(&a[i]);
        __m256 vb = _mm256_load_ps(&b[i]);
        __m256 vc = _mm256_add_ps(va, vb); // a + b
        _mm256_store_ps(&c[i], vc);
    }

    // `Verify' first few results
    printf("Result c[0] = %.2f\n", c[0]);
    printf("Result c[1] = %.2f\n", c[1]);
    printf("Result c[2] = %.2f\n", c[2]);
    printf("\n");
    // Free memory
    free(a); free(b); free(c);
    return 0;
}
