#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h> // Include LIKWID header

#define ROWS 5000
#define COLS 100

double x[ROWS][COLS];

void loop_interchange_optimized() {
    likwid_markerStartRegion("compute"); // Start LIKWID marker

    for (int i = 0; i < ROWS; i++) { // Iterate row-wise for better cache locality
        for (int j = 0; j < COLS; j++) {
            x[i][j] = 2 * x[i][j];  // Process row elements in order
        }
    }

    likwid_markerStopRegion("compute"); // Stop LIKWID marker
}

int main() {
    likwid_markerInit(); // Initialize LIKWID marker API

    // Initialize the array with sample values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            x[i][j] = (double)(i + j);
        }
    }

    loop_interchange_optimized(); // Call the optimized function

    likwid_markerClose(); // Close LIKWID marker API
    return 0;
}
