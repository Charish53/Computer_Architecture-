#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h> // Include LIKWID header

#define N 1000

volatile int val[N]; // Use volatile to prevent compiler optimizations
volatile int key[N];

void array_merge_unoptimized() {
    likwid_markerStartRegion("compute"); // Start LIKWID marker

    for (int i = 0; i < N; i++) {
        val[i] = val[i] + key[i]; // Separate arrays cause more cache misses
    }

    likwid_markerStopRegion("compute"); // Stop LIKWID marker
}

int main() {
    likwid_markerInit(); // Initialize LIKWID marker API

    // Ensure the arrays are initialized
    for (int i = 0; i < N; i++) {
        val[i] = i;
        key[i] = i;
    }

    array_merge_unoptimized(); // Run function

    likwid_markerClose(); // Close LIKWID marker API
    return 0;
}
