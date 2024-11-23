/*

1) Si generi una matrice di dimensione N × M – con N ed M a piacere –
di numeri double.

2) Si codifichi una funzione che prenda in input la matrice e crei un file
contenente tale matrice in formato testo. In particolare, la prima riga di
tale file dovrà contenere i due numeri N ed M.

3) Si codifichi una funzione in grado di leggere un file come quello creato
al punto precedente e quindi di caricare una tale matrice in memoria.

4) Si codifichi una ulteriore funzione che, data una matrice N × M, ne
calcoli la sua trasposta.

5) Si usi infine la funzione codificata al punto due per salvare tale
matrice trasposta su file.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double genDoubleRandom (double a, double b) {
     return a + ((double)rand() / RAND_MAX) * (b - a);
}

int mkFile(char *path, int n, int m, double (*matrix)[m]) {
    FILE *fp = fopen(path, "w+");
    fprintf(fp, "%d %d\n", n, m);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fp, "%lf ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 1;
}

void readFile(char *path) {
    FILE *fp = fopen(path, "r");
    int n = 0, m = 0;
    fscanf(fp, "%d %d", &n, &m); // Leggo le dimensioni
    printf("%d %d\n", n, m);
    double matrix [n][m];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //Leggo
            fscanf(fp, "%lf", &matrix[i][j]);
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main () {
    srand(time(0));
    char *path = "\\mnt\\c\\c\\file.txt";
    int N = 5, M = 5;
    double matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = genDoubleRandom(5.0, 15.0);
        }
    }

    mkFile(path, N, M, matrix);
    readFile(path);
    return 0;
}