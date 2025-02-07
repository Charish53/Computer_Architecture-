#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

#define N 1000
#define B 32 // Blocking factor

volatile double x[N][N], y[N][N], z[N][N];

void blocking_unoptimized() {
    likwid_markerStartRegion("compute");

    for (int i = 0; i < N; i++) { // No blocking → more cache misses
        for (int j = 0; j < N; j++) {
            double r = 0;
            for (int k = 0; k < N; k++) { // Accessing entire row each time
                r += y[i][k] * z[k][j];
            }
            x[i][j] += r;
        }
    }

    likwid_markerStopRegion("compute");
}

int main() {
    likwid_markerInit();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = 0.0;
            y[i][j] = (double)(i + j);
            z[i][j] = (double)(i - j);
        }
    }

    blocking_unoptimized();

    likwid_markerClose();
    return 0;
}
