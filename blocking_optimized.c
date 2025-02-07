#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define B 32 // Blocking factor

double x[N][N], y[N][N], z[N][N];

void matrix_multiplication_optimized() {
    for (int jj = 0; jj < N; jj += B) {
        for (int kk = 0; kk < N; kk += B) {
            for (int i = 0; i < N; i++) {
                for (int j = jj; j < (jj + B < N ? jj + B : N); j++) {
                    double r = 0;
                    for (int k = kk; k < (kk + B < N ? kk + B : N); k++) {
                        r += y[i][k] * z[k][j]; // Better cache reuse
                    }
                    x[i][j] += r;
                }
            }
        }
    }
}

int main() {
    matrix_multiplication_optimized();
    return 0;
}
