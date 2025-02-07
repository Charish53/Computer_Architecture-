#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

#define N 1000

volatile double a[N][N], b[N][N], c[N][N], d[N][N];

void loop_fusion_optimized() {
    likwid_markerStartRegion("compute");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = 1 / b[i][j] * c[i][j];  // First computation
            d[i][j] = a[i][j] + c[i][j];      // Second computation (fused)
        }
    }

    likwid_markerStopRegion("compute");
}

int main() {
    likwid_markerInit();

    // Initialize arrays to prevent undefined behavior
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = (double)(i + j + 1);
            c[i][j] = (double)(i - j);
        }
    }

    loop_fusion_optimized();

    likwid_markerClose();
    return 0;
}
