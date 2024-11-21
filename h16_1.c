/* 

Codificare una funzione C che prenda in input un parametro
formale matrice M di dimensioni n × m di stringhe (puntatori a
caratteri), 
e che restituisca il valore true (1) se esiste almeno 
una colonna in M che abbia un egual numero 
di stringhe palindrome di una delle righe di M.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isPal(char *str) {
    int z = 0;
    //calcolo lunghezza stringa
    while (str[z] != '\0') {
        z++;
    }

    //Ottengo reverse
    char * reverse = (char * ) calloc(z, sizeof(char));
    int c = 0;
    for(int i = z-1; i >= 0; i--) {
        reverse[c] = str[i];
        c++;
    }

    for(int i = 0; i < z; i++) {
        if(str[i] != reverse[i]) { //Se  c'è almeno un carattere diverso, ritorno 0
            return 0;
        }
    }
    return 1; //Altrimenti ritorno 1.
}

int checkPal (char ***matrix, int n, int m, int l) {
    //Controllo per ogni riga quante stringhe palindrome ci sono
    for(int i = 0; i < n; i++) {
        int cRow = 0;
        for (int j = 0; j < m; j++) {
            if(isPal(matrix[i][j])) {
                cRow += 1;
            }
        }
        if(cRow > 0) {
            for (int j = 0; j < m; j++) {
                int cCol = 0;
                for(int i = 0; i < n; i++) {
                    if(isPal(matrix[i][j])) {
                        cCol += 1;
                    }
                }

                if(cRow == cCol)
                    return 1;
            }
        }
    }
    return 0;
}

int main () {
    int n = 0, m = 0;
    printf("Digita n: \n");
    scanf("%d", &n);
    printf("Digita m:\n");
    scanf("%d", &m);

    //Alloco le righe
    char ***matrix = (char ***) calloc(n, sizeof(char**));
    for (int i = 0; i < n; i++) {
        //alloco le colonne
        matrix[i] = (char **) calloc(m, sizeof(char*));
        for (int j = 0; j < m; j++) {
            //alloco il puntatore a una stringa per ogni cella
            matrix[i][j] = (char *) calloc(50, sizeof(char));
            strcpy(matrix[i][j], "anna");
        }
        printf("\n");
    }

    printf("%d\n", checkPal(matrix, n, m, 50));

    free(matrix);
    matrix = NULL;
    return 0;
}