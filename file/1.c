/*

Esercizio 1: Apertura e lettura di un file
Scrivi un programma in C che:

-Apre un file chiamato input.txt in modalità lettura (r).
-Legge la prima parola del file utilizzando la funzione fscanf.
-Stampa la parola letta sullo schermo.
-Chiude il file correttamente.

*/
#include <stdio.h>
int main () {
    const char *filename = "input.txt";
    char str[50] = {'\0'};
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("ERRORE.\n");
        return -1;
    } 
    
    fscanf(file, "%s", str);
    printf("str: %s\n", str);
    fclose(file);
    return 0;
}