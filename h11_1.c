/* 

Codificare un programma in linguaggio C che operi 
un numero indefinito di volte la moltiplicazione 
di un numero in virgola mobile y > 0 per un
altro numero in virgola mobile x < 1: y ← y ∗ x.

Ad ogni iterazione si stampi il risultato della moltiplicazione.

L’algoritmo deve terminare quando si verifica 
la condizione di underflow, ovvero il risultato 
viene approssimato con lo zero.

Codificare l’algoritmo anche con un numero di partenza y < 0, 
stampare il risultato finale (lo 0 “negativo”).

Stampare i risultati in notazione scientifica.

*/
#include <stdio.h>
#include <float.h>

void doMultiplication(float y, float x) {
    while(y > FLT_MIN || y < -FLT_MIN) {
        y *= x;
        printf("%E\n", y);
    }
}

int main () {
    float y = 0.0, x = 0.0;
    
    do {
        printf("Digita y: ");
        scanf("%f", &y);

        printf("Digita x: ");
        scanf("%f", &x);
        
        printf("\n");
    } while (y <= 0 || x >= 1);

    doMultiplication(y, x);

    do {
        printf("Digita y (< 0): ");
        scanf("%f", &y);

        printf("Digita x: ");
        scanf("%f", &x);
        
        printf("\n");
    } while (y >= 0 || x >= 1);

    doMultiplication(y, x);

    return 0;
}