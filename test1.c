#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int genRandomInteger(int a, int b) {
    return rand()%(b - a + 1) + a;
}

//In questo metodo, ptr è un array di dimensione v di puntatori a int
//L'asterisco *, prima di ptr, si applica a ogni elemento dell'array.
//Ogni elemento dell'array è quindi un puntatore a un int. Graficamente:
/* 
 ptr ──┬───> int
       ├───> int
       ├───> int
       ...
       (v puntatori a int)
 */
void printMatrix(int *ptr[], int v, int l) {
    for (int i = 0; i < v; i++) {
        for(int j = 0; j < l; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

void printMatrix1(int *(ptr)[], int v, int l) {
    for (int i = 0; i < v; i++) {
        for(int j = 0; j < l; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}

int main () {
    srand(time(0));
    int v = 10, l = 5;
    int *ptr[10];
    for(int i = 0; i < v; i++) {
        ptr[i] = (int *) malloc(sizeof(int) * l);
        for(int j = 0; j < l; j++) {
            ptr[i][j] = genRandomInteger(0, 100);
            // printf("%d ", ptr[i][j]);    
        }
        // printf("\n");
    }

    // printMatrix(ptr, v, l);
    printMatrix1(ptr, v, l);

    return 0;
}