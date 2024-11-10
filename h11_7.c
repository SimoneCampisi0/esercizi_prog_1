/* 

Codificare un programma in linguaggio C che calcoli e stampi
l’ipotenusa di un triangolo rettangolo.

L’utente dovrà inserire i due cateti a e b da tastiera. 
Il programma dovrà controllare che i valori inseriti siano positivi.

*/
#include <stdio.h>
#include <math.h>
int main () {
    float a = 0.0, b = 0.0, ip = 0.0;
    do {
        printf("Digita a: ");
        scanf("%f", &a);

        printf("Digita b: ");
        scanf("%f", &b);
    } while (a <= 0 || b <= 0);

    ip = sqrt((a*a) + (b * b));
    printf("ipotenusa: %f\n", ip);

    return 0;
}