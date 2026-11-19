#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 536870912

int main()
{

    float *a = (float *)malloc(SIZE*sizeof(float));
    float *b = (float *)malloc(SIZE*sizeof(float));
    float *c = (float *)malloc(SIZE*sizeof(float));

    // Initialize arrays
    for (int i=0; i<SIZE; i++){
        a[i] = (float)i;
        b[i] = (float)(i * 2);
    }

    // Compute element-wise addition
    for (int i=0; i<SIZE; i++){
        c[i] = a[i] + b[i];
    }

    // `Verify' first few results
    printf("Result c[0] = %.2f\n", c[0]);
    printf("Result c[1] = %.2f\n", c[1]);
    printf("Result c[2] = %.2f\n", c[2]);
    printf("\n");

    return 0;
}
