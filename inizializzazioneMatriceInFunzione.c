#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double genDoubleRandom(double a, double b) {
    return a + ((double) rand() / RAND_MAX) * (b - a);
}
void initializeMatrix(double ***arr, int n, int m) {
    //inizializzo le righe
    *arr = malloc(sizeof(double *) * n);
    for(int i = 0; i < n; i++) {
        //inizializzo le colonne
        (*arr)[i] = malloc(sizeof(double) * m);
        for (int j = 0; j < m; j++) {
            (*arr)[i][j] = genDoubleRandom(1.0, 10.0);
            printf("%lf ", (*arr)[i][j]);
        }
        printf("\n");
    }
}

int main () {
    srand(time(0));
    // int a[] = {1,2,3,4,5};
    // int *arr = &a[1];

    double **arr;
    //Bisogna passare l'indirizzo della prima cella a cui punta la matrice.
    initializeMatrix(&arr, 2, 3);
}