/* 

Codificare in C un programma battaglia navale in cui l’utente gioca
contro il calcolatore.
Il programma chiede all’utente le seguenti informazioni:
• il nome del giocatore
• la dimensione del campo di gara
• la dimensione della tabella di gara.
• la dimensione minima e massima delle navi, intesa come
numero di celle occupate da ogni nave.


1 corazzata = 4 len
3 sottomarini = 3 caselle
3 corvette = 2 caselle
2 lance = 1 casella
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int dim_tab, char matrix[dim_tab][dim_tab]) {
    for (int i = 0; i < dim_tab + 2; i++) {
        for (int j = 0; j < dim_tab + 2; j++) {
            if (i == 0 || i == dim_tab + 1) {
                printf("-");
            } else if (j == 0 || j == dim_tab + 1) {
                printf("|");
            } else {
                printf("%c", matrix[i - 1][j - 1]);
            }
        }
      printf("\n");
    }
}

int generateRandom (int a, int b) {
    return rand()%(b - a + 1) + a;
}

void generateShip(int dim_tab, char campo[dim_tab][dim_tab], int dim_minima_nave, int dim_massima_nave) {
    int num_navi = 0;
    //Massimo 5 navi per giocatore
    while (num_navi < 5) {
        int len_nave = generateRandom(dim_minima_nave, dim_massima_nave);
        int x = generateRandom(0, dim_tab - 1);
        int y = generateRandom(0, dim_tab - 1);

        //TODO: scrivere algoritmo per posizionare casualmente le navi rimanendo dentro i bordi


    }
}

void gioca(int len_nome, char nome[len_nome], int dim_campo, int dim_tab, int dim_minima_nave, int dim_massima_nave) {
    char campo_player [dim_tab][dim_tab], campo_cpu[dim_tab][dim_tab];
    char tabella_player[dim_tab][dim_tab], tabella_cpu[dim_tab][dim_tab];
    for (int i = 0; i < dim_tab; i++) {
        for (int j = 0; j < dim_tab; j++) {
            campo_player[i][j] = ' ';
            campo_cpu[i][j] = ' ';
            tabella_player[i][j] = ' ';
            tabella_cpu[i][j] = ' ';
        }
    }

    generateShip(dim_tab, campo_player, dim_minima_nave, dim_massima_nave);
    generateShip(dim_tab, campo_cpu, dim_minima_nave, dim_massima_nave);

    
    printMatrix(dim_tab, campo_player);
    printMatrix(dim_tab, campo_cpu);
}


int main () {
    srand(time(0));
    int r = 0, dim_campo = 0, dim_tab;
    int dim_minima_nave = 0, dim_massima_nave = 0;
    char nome [50] = {};
    do {
        printf("1 - carica dati\n2 - gioca\n0 - esci.\n");
        scanf("%d", &r);
        switch(r) {
            case 0:
                printf("sto uscendo...\n"),
                system("cls");
                break;
            case 1:
                // printf("digita il tuo nome: \n");
                // scanf("%s",nome);
                // printf("digita la dimensione del campo di gara:\n");
                // scanf("%d",&dim_campo);
                printf("digita la dimensione della tabella di gara:\n");
                scanf("%d", &dim_tab);
                printf("digita la dimensione minima delle navi:\n");
                scanf("%d",&dim_minima_nave);
                printf("digita la dimensione massima delle navi:\n");
                scanf("%d",&dim_massima_nave);
                break;
            case 2:
                gioca(50, nome, dim_campo, dim_tab, dim_minima_nave, dim_massima_nave);
                break;
            default:
                printf("Voce non in elenco, riprova...");
                system("cls");
                break;
        };
    } while (r != 0);

    return 0;
}