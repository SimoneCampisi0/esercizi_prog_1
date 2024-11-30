/*

Scrivi un programma in C che:

-Apre un file chiamato source.txt in modalità lettura (r).
-Crea un nuovo file chiamato destination.txt in modalità scrittura (w).
-Copia ogni riga dal file sorgente a quello di destinazione usando fgets e fputs.
-hiude entrambi i file.

*/
#include <stdio.h>
#include <stdlib.h>
int main () {
    const char *src_filename = "source.txt";
    const char *out_filename = "destination.txt";
    char buffer[2048];

    FILE *src = fopen(src_filename, "r");
    if(src == NULL) {
        perror("Errore.\n");
        return EXIT_FAILURE;
    }
    FILE *out = fopen(out_filename, "w");
    if(out == NULL) {
        perror("Errore.\n");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), src) != NULL)
    {
        fputs(buffer, out);
    }
    fclose(src);
    fclose(out);
    return 0;
}