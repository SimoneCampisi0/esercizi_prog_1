/*

Codificare in C un programma per il metodo montecarlo per
il calcolo (approssimato) del numero π sulla base che si basi
sull’esempio E13.1.

NB: Il numero di campionamenti deve essere scelto
dall’utente a tempo di esecuzione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randomFrom(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main () {
    int n = 0, s = 0;
    printf("Digita il numero dei campionamenti: ");
    scanf("%d", &n);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        double x = randomFrom(-1.0, 1.0);
        double y = randomFrom(-1.0, 1.0);

        double ver = (x * x) + (y * y);
        if(ver <= 1) {
            // printf("Successo\n");
            s+=1;
        } else {
            // printf("Fallimento\n");
        }
    }
    
    long double success = (long double)s / n;
    // printf("%d successi su %d lanci\n", s, n);
    // printf("con tasso %lf%%\n", success * 100);
    printf("Approssimazione di π: %.25Lf\n", success * 4);

    return 0;
}