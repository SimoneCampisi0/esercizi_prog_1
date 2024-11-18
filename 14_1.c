/*
Dichiarare e inizializzare tre variabili:
double
short unsigned
char
Assegnare a ciascuna valori a piacere.
Dichiarare altrettante variabili puntatore dello stesso tipo e assegnare loro gli indirizzi delle variabili dichiarate in precedenza.

Stampare i valori contenuti all'interno delle variabili con printf() in due modi differenti:

i) Mediante le variabili stesse.
ii) Mediante le variabili puntatore.
Stampare, sempre con printf(), i valori contenuti all'interno dei puntatori (ovvero gli indirizzi di memoria).
*/
#include <stdio.h>
int main () {
    double x = 5.5;
    unsigned short y = 10;
    char z = 'c';

    double *px = &x;
    unsigned short *py= &y;
    char *pz = &z;

    printf("%lf\n", x);
    printf("%lf\n", *px); 
    printf("%p\n", px);

    printf("%d\n", y); 
    printf("%d\n", *py); 
    printf("%p\n", py);

    printf("%d\n", z); 
    printf("%d\n", *pz); 
    printf("%p\n", pz);

    return 0;
}