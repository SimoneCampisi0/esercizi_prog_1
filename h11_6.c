#include <stdio.h>
int visitCognome(int lCognome, char cognome[], char c) {
    for (int i = 0; i < lCognome; i++) {
        if(cognome[i] == c) {
            return 1;
        }
    }
    return 0;
}

void filterConsonants(int l, char arr[]) {
    int c = 0;
    for (int i = 0; i < l; i++) {
        if(arr[i] != 'a' && arr[i] !='e' && arr[i] != 'i' && arr[i] != 'o' && arr[i] != 'u') {
            c++;
        }
    }

    printf("numero cifre: %d\n", c);
}

int main () {
    int lNome = 0, lCognome = 0;
    printf("digita l. nome: ");
    scanf("%d", &lNome);
    printf("digita l. cognome: ");
    scanf("%d", &lCognome);

    char nome[lNome], cognome[lCognome];

    printf("digita nome: ");
    scanf("%s", nome); //Non si passa l'indirizzo con & perché scanf necessita
    //del puntatore
    printf("digita cognome: ");
    scanf("%s", cognome);

    //1 - primo e ultimo carattere del nome
    // printf("%c %c\n", nome[0], nome[lNome - 1]);
    // printf("%c %c\n", cognome[1], cognome[2]);

    //2
    char out[lNome + lCognome];
    int c = 0;
    for (int i = 0; i < lNome; i++) {
        if(visitCognome(lCognome, cognome, nome[i]) == 1) {
            printf("nome[%d]: %c\n", i, nome[i]);
            out[c] = nome[i];
            c++;
        }
    }
    out[c] = '\0';
    printf("out: %s\n", out);

    //3 - a
    nome[0] == cognome[lCognome - 1] ? printf("Ultime lettere uguali\n") : printf("Ultime lettere non uguali\n");

    //3 - b
    lNome == lCognome ? printf("Nome e cognome hanno la stessa lunghezza\n") : printf("Nome e cognome non hanno la stessa lunghezza\n");

    //3 - c
    filterConsonants(lNome, nome);
    filterConsonants(lCognome, cognome);
}



