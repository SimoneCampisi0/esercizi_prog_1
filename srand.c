#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main () {
    //Estrae il numero casuale dal seme fornito.
    //Il numero fornito sarà sempre lo stesso, se la sequenza non varia
    srand(111222333);

    //Oppure si può utilizzare il comando time(0)
    //che genera il valore casuale in base
    //a quanti secondi sono decorsi a partire dal 1 gennario 1970
    //rispetto all'istante attuale d'esecuzione
    srand(time(0));

    for(int i = 0; i < 5; i++)
        printf("%d\n", rand());

    printf("RAND_MAX: %d\n", RAND_MAX);
    // double r = rand() / (RAND_MAX * 1.0);
    double r = ((double) rand()) / RAND_MAX;
    printf("Double generato casualmente: %lf\n", r);

    int b = 5, a = 2;
    unsigned int r = rand()%(b - a + 1) + a;
}