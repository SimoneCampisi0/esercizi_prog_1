/*

Codificare un programma in linguaggio C che chieda all’utente di
inserire tre numeri da tastiera. 
L’utente può inserire numeri interi o decimali.

Il programma dovrà stampare, per ogni numero in input,
l’arrotondamento al valore intero più vicino.

*/
#include <stdio.h>
#include <math.h>
int main () {
    float a = 0.0, b = 0.0, c = 0.0;

    printf("digita a: ");
    scanf("%f", &a);
    printf("digita b: ");
    scanf("%f", &b);
    printf("digita c: ");
    scanf("%f", &c);

    // int a1 = (int)round(a);
    int a1 = round(a);
    int b1 = (int)round(b);
    int c1 = (int)round(c);

    printf("a1: %d\n", a1);
    printf("b1: %d\n", b1);
    printf("c1: %d\n", c1);

}