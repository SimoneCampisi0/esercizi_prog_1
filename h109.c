/* 

Codificare un programma che chiede all’utente di inserire due
numeri decimali maggiori di zero e diversi tra loro (ES: 10.2
e 24.7), ed un numero intero N > 1.
• il programma calcola l’arrotondamento di entrambi i
numeri all’intero pi`u vicino, Siano a e b i due numeri
ottenuti, con a < b.
• per ogni numero a ≤ p ≤ b, calcola e stampa la
somma degli N-1 numeri minori di p e la somma dei
2N numeri maggiori di p;


*/

#include <stdio.h>
#include <math.h>
void calcSumN1(int p, int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i > p) {
            break;
        }
        sum+=i;
    }
    // printf("SumN1: %d\n", sum);
}

void calcSum2N(int p, int N) {
    int sum = 0;
    for (int i = 1; i <= (N * 2); i++) {
        printf("p: %d\n", p);
        p+=1;
        sum+=p;
        printf("Sum2N: %d\n", sum);
    }
}

int main () {
    float n1 = 0.0, n2 = 0.0;
    int a = 0, b = 0;
    int N = 0;
    do {
        printf("Digita a (> 0): ");
        scanf("%f", &n1);

        printf("Digita b (> 0): ");
        scanf("%f", &n2);
    } while (n1 <= 0 || n2 <= 0 || n1 == n2);

    printf("Digita N: ");
    scanf("%d", &N);

    a = (int)round(n1);
    b = (int)round(n2);
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    if(a < b) {
        for (int p = a; p <= b; p++) {
            printf("p: %d\n\n\n", p);
            calcSumN1(p, N);
            calcSum2N(p, N);
        }
    }


    return 0;
}