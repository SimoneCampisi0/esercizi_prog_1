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
#include <string.h>
double genDoubleRandom(int a, int b) {
    return a + ((double)rand() / RAND_MAX) * (b - a);
}

// void makeFile(int n, int m, double **mat){
void makeFile(int n, int m, double *mat[m]){
    const char * filename = "file.txt";
    char buffer[1024] = {"\0"};
    char temp[1024] = {"\0"};

    FILE *file = fopen(filename, "w");
    if(!file) {
        printf("ERROR.\n");
        return;
    }
    sprintf(temp, "%d", n);
    strcat(buffer, temp);

    strcat(buffer, " ");

    sprintf(temp, "%d", m);
    strcat(buffer, temp);

    fputs(buffer, file);
    fputs("\n", file);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            sprintf(buffer, "%f ", *(*(mat + i) + j));
            fputs(buffer, file);
        }
        fputs("\n", file);
    }

    fclose(file);
}

double **uploadMatrix() {
    const char * filename = "file.txt";
    int n = 0, m = 0;
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("ERROR.\n");
        system("pause");
    }

    fscanf(file, "%d", &n);
    fscanf(file, "%d", &m);

    double **matrix = (double **) malloc(sizeof(double *) * n);
    for (int i = 0; i < n; i++) {
        *(matrix + i) = (double *) malloc(sizeof(double) * m);
        for (int j = 0; j < m; j++) {
            // fscanf(file, "%lf", (*(matrix + i) + j));
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }
    return matrix;
}
int main () {
    int n = 5, m = 4;
    double **mat = (double **) calloc(n, sizeof(double *));
    for(int i = 0; i < n; i++) {
        *(mat + i) = (double *) calloc(m, sizeof(double));
        for(int j = 0; j < m; j++) {
            *(*(mat + i) + j) = genDoubleRandom(0, 100);
        }
    }
    makeFile(n,m,mat);
    double **matrix = uploadMatrix();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}