#include <stdio.h>
void valore(int x) {
    x = 10;
}

void indirizzo (int *x) { //Passaggio per indirizzo
    *x = 10;   
}

int main () {
    int x = 5;
    valore(x);
    printf("Passaggio per valore: %d\n", x);

    indirizzo(&x);
    printf("Passaggio per indirizzo: %d\n", x);

    return 0;
}