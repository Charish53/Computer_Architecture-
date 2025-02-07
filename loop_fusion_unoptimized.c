#include <stdio.h>
#include <stdlib.h>

#define N 1000

double a[N][N], b[N][N], c[N][N], d[N][N];

void loop_fusion_unoptimized() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 1 / b[i][j] * c[i][j]; // First loop

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = a[i][j] + c[i][j]; // Second loop accessing the same data
}

int main() {
    loop_fusion_unoptimized();
    return 0;
}
