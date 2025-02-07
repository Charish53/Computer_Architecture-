#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <likwid.h>  // Include LIKWID header

#define N 1000

struct merge {
    int val;
    int key;
};

void array_merged() {
    likwid_markerStartRegion("compute");  // Start performance region
    struct merge merged_array[N];

    // Initialize the array to avoid undefined behavior
    for (int i = 0; i < N; i++) {
        merged_array[i].val = i;  
        merged_array[i].key = i;  
    }

    // Start computation
    for (int i = 0; i < N; i++) {
        merged_array[i].val = merged_array[i].val + merged_array[i].key; 
    }
    likwid_markerStopRegion("compute");  // Stop performance region
}

int main() {
    likwid_markerInit();  // Initialize LIKWID marker API
    

    array_merged(); // Call function

    
    likwid_markerClose();  // Close LIKWID marker API

    return 0;
}
