/*
Codificare in linguaggio C un programma che produca la somma 
dei numeri interi dispari da 1 a 99, 
facendo uso del costrutto for. 
Dalla somma vanno esclusi i numeri divisibili per tre.*/
#include <stdio.h>
int main () {
    int s = 0;
    for (int i = 1; i <= 99; i++) {
        (i % 2 != 0 && i % 3 != 0) ? s+=i : 0;
    }
    printf("somma: %d\n", s);

    return 0;
}