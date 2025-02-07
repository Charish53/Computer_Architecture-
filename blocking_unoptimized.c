#include <stdio.h>
#include <stdlib.h>

#define N 1000

double x[N][N], y[N][N], z[N][N];

void matrix_multiplication_unoptimized() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double r = 0;
            for (int k = 0; k < N; k++) {
                r += y[i][k] * z[k][j]; // Poor cache reuse
            }
            x[i][j] = r;
        }
    }
}

int main() {
    matrix_multiplication_unoptimized();
    return 0;
}
