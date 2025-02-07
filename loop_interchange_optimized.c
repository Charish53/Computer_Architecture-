#include <stdio.h>
#include <stdlib.h>

#define N 5000
#define M 100

double x[N][M];

void loop_interchange_optimized() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            x[i][j] = 2 * x[i][j]; // Sequential access improves locality
        }
    }
}

int main() {
    loop_interchange_optimized();
    return 0;
}
