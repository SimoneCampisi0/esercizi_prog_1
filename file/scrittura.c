/*

Scrivi un programma in C che:

-Crea (o sovrascrive) un file chiamato output.txt in modalità scrittura (w).
-Scrive la frase "Hello, world!" nel file utilizzando la funzione fputs.
-Chiude il file correttamente.

*/
#include <stdio.h>
int main () {
    const char *filename = "output.txt";
    FILE *file = fopen(filename, "w");
    if(!file) {
        printf("ERRORE.\n");
        return -1;
    }

    fputs("Hello, world!", file);
    fclose(file);
    return 0;
}