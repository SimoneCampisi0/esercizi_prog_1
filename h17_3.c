/* 

Scrivere un programma che chieda in input al’utente nome e cognome,
da memorizzare in due array di caratteri distinti.

Definire quindi un array di caratteri che possa contenere sia nome che
cognome separati da un carattere ’;’, senza spazi.

Copiare nome e cognome mediante la funzione strcpy nel nuovo array di
caratteri, senza dimenticare il carattere ’;’.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {
    char *nome = (char *) calloc(50, sizeof(char));
    char *cognome = (char *) calloc(50, sizeof(char));
    printf("Digita nome: ");
    scanf("%s", nome);
    printf("Digita cognome: ");
    scanf("%s", cognome);

    char *unione = (char *) calloc((strlen(nome) + strlen(cognome) + 2), sizeof(char));
    strcpy(unione, nome);
    strcpy(unione + strlen(nome), ";"); //Questo è possibile dato che il primo argomento rappresenta l'indice da cui si copia il valore del secondo argomento.
    strcpy(unione + strlen(nome) + 1, cognome);
    printf("unione: %s\n", unione);

    return 0;
}