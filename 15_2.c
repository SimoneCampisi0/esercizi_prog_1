/* 

Modificare il precedente esercizio affinch`e la funzione prenda in
input, oltre alla coppia di interi short, anche un puntatore ad
numero short unsigned.

La funzione dovr`a scrivere il risultato della computazione nella
locazione di memoria rappresentata dal puntatore in input. La
funzione non avr`a alcun tipo di ritorno.

Invocare la funzione all’interno di una funzione main() con alcuni
valori di test. Stampare opportunamente i risultati.

*/
#include <stdio.h>
#include <stdlib.h>
void valoreAssoluto(short int x, short int y, unsigned short int *p) {
    short int r = x * y;

    *p = r <= 0 ? r * -1 : r;
}

int main () {
    short int x = 5, y = 6;
    unsigned short int *p = (unsigned short int *) malloc(sizeof(unsigned short int)); //Allocato dinamicamente per eliminare il warning
    valoreAssoluto(x, y, p);
    printf("%d\n", *p);
    return 0;
}