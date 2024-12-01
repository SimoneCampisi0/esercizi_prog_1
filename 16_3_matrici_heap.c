#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genIntRand(int a, int b) {
    return rand() % (b - a + 1) + a;
}

double *fun(int n, int m, int k, int *a[], int *b[]) {
    double *c = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        int a_sum = 0, b_sum = 0;
        for (int j = 0; j<m; j++) {
            a_sum+=a[i][j];
        }
        for(int j = 0; j < k; j++) {
            b_sum+=b[j][i];
        }
        double rapp = (double) a_sum / b_sum;
        *(c + i) = rapp;
    }
    return c;
}

int main() {
    srand(time(0));
    int n = 5, m = 10, k = 15;
    
    int **a = malloc(sizeof(int *) * n);
    printf("matrice a:\n");
    for (int i = 0; i < n; i++) {
        *(a + i) = malloc(sizeof(int) * m);
        for(int j = 0; j < m; j++) {
            *(*(a + i) + j) = genIntRand (0, 100);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nmatrice b:\n");
    int **b = (int **) malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++) {
        *(b + i) = malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) {
            *(*(b + i) + j) = genIntRand (0, 100);
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    double *c = fun(n,m,k,a,b);
    for(int i = 0; i<n; i++)
        printf("%f\n", *(c + i));

    //rilascio
    for(int i = 0; i < n; i++) {
        free(a[i]);
    }
    for(int i = 0; i < k; i++) {
        free(b[i]);
    }
    free(c);
    return 0;
}