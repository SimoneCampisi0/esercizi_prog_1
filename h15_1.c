/* 

Codificare una funzione in C che prenda in input una coppia di
interi short con segno e restituisca il valore assoluto 
del prodotto di tali interi.
Invocare la funzione all’interno di una funzione main() con alcuni
valori di test.
*/


#include <stdio.h>
#include <stdlib.h>
int valoreAssoluto(int x, int y) {
    short int r = x * y;

    return r <= 0 ? r * -1 : r;
}
int main () {
    short int x = 5, y = 6;
    printf("%d\n", valoreAssoluto(x, y));
    return 0;
}