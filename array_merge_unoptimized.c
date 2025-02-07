#include <stdio.h>
#include <stdlib.h>

#define N 1000

void array_separate() {
    int val[N], key[N];
    for (int i = 0; i < N; i++) {
        val[i] = val[i] + key[i]; // Separate arrays cause more cache misses
    }
}

int main() {
    array_separate();
    return 0;
}
