#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>  // Include LIKWID header for performance analysis

#define N 1000
#define B 32 // Blocking factor

double x[N][N], y[N][N], z[N][N];

void matrix_multiplication_optimized() {
    likwid_markerStartRegion("compute"); // Start LIKWID marker

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

    likwid_markerStopRegion("compute"); // Stop LIKWID marker
}

int main() {
    likwid_markerInit(); // Initialize LIKWID marker API

    // Initialize matrices to ensure proper data access
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = 0.0;
            y[i][j] = (double)(i + j);  // Example initialization
            z[i][j] = (double)(i - j);
        }
    }

    matrix_multiplication_optimized(); // Perform matrix multiplication

    likwid_markerClose(); // Close LIKWID marker API
    return 0;
}
