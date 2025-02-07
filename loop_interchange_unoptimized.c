#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>

#define ROWS 5000
#define COLS 100

volatile double x[ROWS][COLS];

void loop_interchange_unoptimized() {
    likwid_markerStartRegion("compute");

    for (int j = 0; j < COLS; j++) { // Inefficient column-major order
        for (int i = 0; i < ROWS; i++) {
            x[i][j] = 2 * x[i][j];
        }
    }

    likwid_markerStopRegion("compute");
}

int main() {
    likwid_markerInit();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            x[i][j] = (double)(i + j);
        }
    }

    loop_interchange_unoptimized();

    likwid_markerClose();
    return 0;
}
