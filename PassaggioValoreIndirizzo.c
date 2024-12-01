#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PASSAGGIO PER VALORE- crea una copia del valore.
void foo (int a) {
    a = 50;
    printf("Valore modificato dentro la funzione: %d\n", a);
}
//PASSAGGIO PER INDIRIZZO- viene passato un puntatore al valore.
void zoo(int *a) {
    *a = 30;
}
int main () {
    int a = 10;
    printf("Valore originale: %d\n", a);
    foo(a);
    printf("Passaggio per valore: %d\n", a);    
    zoo(&a);
    printf("Passaggio per indirizzo: %d\n", a);
}