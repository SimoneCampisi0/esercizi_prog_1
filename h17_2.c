/*

Definire tre stringhe di lunghezza random che sia compresa tra 10 e 20.

Riempire le tre stringhe con caratteri pseudocasuali che appartengano
agli intervalli [a-z, 0-9].

Eseguire un confronto lessicografico delle tre stringhe mediante la
funzione strcmp.

Infine stampare le tre stringhe, una riga dopo l’altra dalla stringa minore
alla stringa maggiore.

*/
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int genIntRandom (int a, int b) {
    return rand() % (b - a + 1 ) + a;
}

void populateArr(char *s, int l) {
    for (int i = 0; i < l; i++) {
        int d = genIntRandom (0, 1);
        if(d) {
            s[i] = genIntRandom(48, 57);
        } else {
            s[i] = genIntRandom(97, 122);
        }
    }
    s[l - 1] = '\0';
}

int main () {
    srand(time(0));
    int l1 = genIntRandom(10, 20);
    int l2 = genIntRandom(10, 20);
    int l3 = genIntRandom(10, 20);
    char *s1 = (char *) calloc(l1, sizeof(char));
    if (s1 == NULL) {
        perror("Errore nell'allocazione di memoria per s1");
        exit(EXIT_FAILURE);
    }
    char *s2 = (char *) calloc(l2, sizeof(char));
    if (s2 == NULL) {
        perror("Errore nell'allocazione di memoria per s2");
        exit(EXIT_FAILURE);
    }
    char *s3 = (char *) calloc(l3, sizeof(char));
    if (s3 == NULL) {
        perror("Errore nell'allocazione di memoria per s3");
        exit(EXIT_FAILURE);
    }
    populateArr(s1, l1);
    populateArr(s2, l2);
    populateArr(s3, l3);

    if(strcmp(s1, s2) > 0) { // s1 > s2
        if(strcmp(s1, s3) > 0) { // s1 > s3
            if(strcmp(s2, s3) > 0) { // s2 > s3
                printf("%s\n%s\n%s\n", s1, s2, s3); // s1 > s2 > s3
            } else {
                printf("%s\n%s\n%s\n", s1, s3, s2); // s1 > s3 > s2
            }
        } else {
            printf("%s\n%s\n%s\n", s3, s1, s2); // s3 > s1 > s2
        }
    } else { // s2 > s1
        if(strcmp(s2, s3) > 0) { // s2 > s3
            if(strcmp(s1, s3) > 0) { // s1 > s3
                printf("%s\n%s\n%s\n", s2, s1, s3); // s2 > s1 > s3
            } else {
                printf("%s\n%s\n%s\n", s2, s3, s1); // s2 > s3 > s1
            }
        } else {
            printf("%s\n%s\n%s\n", s3, s2, s1); // s3 > s2 > s1
        }
    }

    free(s1);
    free(s2);
    free(s3);

    return 0;
}