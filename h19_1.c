/* 

Definire una struttura (struct) record che contenga un numero in virgola
mobile, un carattere e due puntatori a caratteri S ed W (due stringhe).

Codificare una funzione che prenda in input un puntatore ad una tale struttura
e che sia in grado di inizializzare la struttura con elementi pseudo-casuali. 

In particolare il campo W dovr`a essere inizializzato con caratteri appartenenti
all’insieme [0-9], il campo S con caratteri in nell’insieme [a-z].
Invocare opportunamente la funzione all’interno della funzione main

*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
struct Record {
    float vm;
    char c;
    char *s;
    char *w;
};

int genRandom (int a, int b) {
    return rand() % (b - a + 1) + a;
}

float genFloatRandom (float a, float b) {
     return a + ((double)rand() / RAND_MAX) * (b - a);
}

void initializeRecord(struct Record **record) {
    *record = (struct Record *) malloc(sizeof(struct Record));
    (*record)->w = (char *) calloc(11, sizeof(char));
    for (int i = 0; i < 10; i++) {
        (*record)->w[i] = genRandom(48, 57);
    }
    (*record)->w[10] = '\0';

    (*record)->s = (char *) calloc(11, sizeof(char));
    for (int i = 0; i < 10; i++) {
        (*record)->s[i] = genRandom(97, 122);
    }

    (*record)->c = genRandom(97, 122);
    (*record)->vm = genFloatRandom(1.0, 10.0);

}

int main () {
    srand(time(0));
    struct Record *record;
    initializeRecord(&record);

    printf("%s\n%s\n%c\n%f\n", (record)->w, (record)->s, (record)->c, (record)->vm);
}