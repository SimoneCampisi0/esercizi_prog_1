/*

Codificare una funzione in C che prenda in input tre parametri
formali: una matrice di stringhe S di dimensioni n × m, un array di
caratteri C che contenga per ipotesi elementi distinti, ed un float w.

Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C
presenti in essa `e maggiore di w.

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int calculateLen(char *s) {
    int z = 0;
    while (s[z] != '\0') {
        z++;
    }
    return z;
}

int isInArray(char *c, int len_c, char *s, int len_s) {
    for(int i = 0; i < len_s; i++) {
        for(int j = 0; j < len_c; j++) {
            if(s[i] == c[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int fun_perc(char ***s, int n, int m, char *c, float w) {
    int len_c = calculateLen(c);

    for(int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < m; j++) {
            int l = calculateLen(s[i][j]);

            printf("s[%d][%d]: %s ", i, j, s[i][j]);

            if(isInArray(c, len_c, s[i][j], l) == 1) {
                count += 1;
            }
        }
        

        if(count > 0) {
            float perc = (count / len_c) * 100;
            if(perc > w) {
                return 1;
            }
        }
    }

    return 0;
}

int main () {
    int n = 0, m = 0;
    char c [] = {'a', 'b', 'c'};
    float w = 5.0;

    printf("Digita n: \n");
    scanf("%d", &n);
    printf("Digita m:\n");
    scanf("%d", &m);

    //Istanzio la lunghezza delle righe
    char ***s = (char ***) calloc(n, sizeof(char **));
    for (int i = 0; i < n; i++) {
        //istanzio, per ogni cella 0 della riga, le sue colonne
        s[i] = (char **) calloc(m, sizeof(char *));
        for (int j = 0; j < m; j++) {
            s[i][j] = (char *) calloc(100, sizeof(char)); //Istanzio gli array di caratteri nelle celle
            strcpy(s[i][j], "zda");
        }
    }

    printf("%d\n", fun_perc(s, n, m, c, w));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            free(s[i][j]);
        }
        free(s[i]);
    }
    free(s);

    return 0;
}