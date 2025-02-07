#include <stdio.h>
#include <stdlib.h>

#define N 1000

struct merge {
    int val;
    int key;
};

void array_merged() {
    struct merge merged_array[N];
    for (int i = 0; i < N; i++) {
        merged_array[i].val = merged_array[i].val + merged_array[i].key; // Improved spatial locality
    }
}

int main() {
    array_merged();
    return 0;
}
