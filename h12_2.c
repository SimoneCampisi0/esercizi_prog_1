#include <stdio.h>
#include <math.h>
int main () {
    float n = 0.0, m = 0.0;
    do {
        printf("n");
        scanf("%f", &n);
        printf("m");
        scanf("%f", &m);
    } while (n <= 1.0 || m <= 1.0);

    int N = (int)round(n);
    int M = (int)round(m);
    float matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = 3.76;
            matrix[i][j] *= 3.542; 
            printf("matrix[%d][%d]: %f ", i, j, matrix[i][j]);
        }
        printf("\n");
    }

    if(N > M) {
        N = M;
    }

    float matrix1[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix1[i][j] = matrix[i][j];
            printf("matrix1[%d][%d]: %f ", i, j, matrix1[i][j]);
        }
        printf("\n");
    }



    return 0;
}