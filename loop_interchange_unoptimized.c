#include <stdio.h>
#include <stdlib.h>

#define N 5000
#define M 100

double x[N][M];

void loop_interchange_unoptimized() {
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            x[i][j] = 2 * x[i][j]; // Strided access causes cache inefficiency
        }
    }
}

int main() {
    loop_interchange_unoptimized();
    return 0;
}
