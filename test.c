#include <stdio.h>
#include <stdlib.h>

void init(int **v, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", *(*(v + i) + j));
        }
        printf("\n");
    }
}

/* Qui è giusto passare int *v[] e non int (*v)[], a differenza del passaggio 
di una matrice allocata nello stack, perché qui rappresenta un array di puntatori,
che puntano ai primi elementi delle righe. A ogni primo elemento di una riga,
è stato allocato dinamicamente un'altra riga, che rappresentano quindi le colonne della matrice. */
void init1(int *v[], int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", *(*(v + i) + j));
        }
        printf("\n");
    }
}

int main () {
    int n = 5, m = 10;
    int **v = malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++) {
        *(v + i) = malloc(sizeof(int) * m);
        // v[i] = malloc(sizeof(int) * m);
        for(int j = 0; j < m; j++) {
            *(*(v + i) + j) = 5;
            // v[i][j] = 5;
        }
    }

    init(v, n, m);
    printf("\n\n\ninit1:\n");
    init1(v, n, m);
    return 0;
}