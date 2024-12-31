/*

Codificare in C un programma battaglia navale in cui l’utente gioca
contro il calcolatore.
Il programma chiede all’utente le seguenti informazioni:
• il nome del giocatore
• la dimensione del campo di gara
• la dimensione della tabella di gara.
• la dimensione minima e massima delle navi, intesa come
numero di celle occupate da ogni nave.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int dim_tab, char matrix[dim_tab][dim_tab])
{
    printf("\n");
    for (int i = 0; i < dim_tab; i++)
    {
        if (i == 0)
        {
            printf(" ");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
    for (int i = 0; i < dim_tab; i++)
    {
        printf("|");
        for (int j = 0; j < dim_tab; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < dim_tab; i++)
    {
        if (i == 0)
        {
            printf(" ");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");
}

int generateRandom(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int isFreeUp(int dim_tab, char campo[dim_tab][dim_tab], int len_nave, int x, int y)
{
    for (int i = x; i >= (x + 1 - len_nave); i--)
    {
        if (campo[i][y] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

int isFreeDown(int dim_tab, char campo[dim_tab][dim_tab], int len_nave, int x, int y)
{
    for (int i = x; i <= (x + 1 + len_nave); i++)
    {
        if (campo[i][y] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

int isFreeLeft(int dim_tab, char campo[dim_tab][dim_tab], int len_nave, int x, int y)
{
    for (int i = y; i >= (y + 1 - len_nave); i--)
    {
        if (campo[x][i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

int isFreeRight(int dim_tab, char campo[dim_tab][dim_tab], int len_nave, int x, int y)
{
    for (int i = y; i <= (y + 1 + len_nave); i++)
    {
        if (campo[x][i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

void generateShip(int dim_tab, char campo[dim_tab][dim_tab], int dim_minima_nave, int dim_massima_nave)
{
    int num_navi = 0;
    // Massimo 5 navi per giocatore
    while (num_navi < 5)
    {
        int len_nave = generateRandom(dim_minima_nave, dim_massima_nave);
        int x = generateRandom(0, dim_tab - 1);
        int y = generateRandom(0, dim_tab - 1);

        // TODO: scrivere algoritmo per posizionare casualmente le navi rimanendo dentro i bordi

        // Genero casualmente l'ordinamento, che va da 1 a 4.
        // 1 -> Genero la nave verso su
        // 2 -> Genero la nave verso sotto
        // 3 -> Genero la nave verso sinistra
        // 4 -> Genero la nave verso destra
        int ordinamento = generateRandom(1, 4);
        char letter = generateRandom(65, 90);
        printf("ordinamento: %d\n", ordinamento);

        switch (ordinamento)
        {
        case 1:
            // Se x > della lunghezza della nave, allora posso salire
            if (((x + 1) - len_nave) >= 0)
            {
                if (isFreeUp(dim_tab, campo, len_nave, x, y) == 1)
                {
                    for (int i = x; i >= (x + 1 - len_nave); i--)
                    {
                        campo[i][y] = letter;
                        // printf("campo[%d][%d]: %c\n", i,y,campo[i][y]);
                    }
                    num_navi += 1;
                }
            }
            break;
        case 2:
            if (((x + 1) + len_nave) <= (dim_tab))
            {
                if (isFreeDown(dim_tab, campo, len_nave, x, y) == 1)
                {
                    for (int i = x; i <= (x + 1 + len_nave); i++)
                    {
                        campo[i][y] = letter;
                        // printf("campo[%d][%d]: %c\n", i,y,campo[i][y]);
                    }
                    num_navi += 1;
                }
            }
            break;
        case 3:
            if (((y + 1) - len_nave >= 0))
            {
                if (isFreeLeft(dim_tab, campo, len_nave, x, y) == 1)
                {
                    for (int i = y; i >= (y + 1 - len_nave); i--)
                    {
                        campo[x][i] = letter;
                    }
                    num_navi += 1;
                }
            }
            break;
        case 4:
            if (((y + 1) + len_nave) <= (dim_tab))
            {
                if (isFreeRight(dim_tab, campo, len_nave, x, y) == 1)
                {
                    for (int i = y; i <= (y + 1 + len_nave); i++)
                    {
                        campo[x][i] = letter;
                    }
                    num_navi += 1;
                }
            }
            break;
        };
    }
}

void gioca(int len_nome, char nome[len_nome], int dim_tab, int dim_minima_nave, int dim_massima_nave)
{
    char campo_player[dim_tab][dim_tab], campo_cpu[dim_tab][dim_tab];
    char tabella_player[dim_tab][dim_tab], tabella_cpu[dim_tab][dim_tab];
    for (int i = 0; i < dim_tab; i++)
    {
        for (int j = 0; j < dim_tab; j++)
        {
            campo_player[i][j] = ' ';
            campo_cpu[i][j] = ' ';
            tabella_player[i][j] = ' ';
            tabella_cpu[i][j] = ' ';
        }
    }

    generateShip(dim_tab, campo_player, dim_minima_nave, dim_massima_nave);
    // generateShip(dim_tab, campo_cpu, dim_minima_nave, dim_massima_nave);

    printf("\n\n\n\nFINE: ");
    printMatrix(dim_tab, campo_player);
    // printMatrix(dim_tab, campo_cpu);
}

int main()
{
    srand(time(0));
    int r = 0, dim_tab = 0;
    int dim_minima_nave = 0, dim_massima_nave = 0;
    char nome[50] = {};
    do
    {
        printf("1 - carica dati\n2 - gioca\n0 - esci.\n");
        scanf("%d", &r);
        switch (r)
        {
        case 0:
            printf("Sto uscendo...\n"),
                system("cls");
            break;
        case 1:
            // printf("digita il tuo nome: \n");
            // scanf("%s",nome);
            // printf("digita la dimensione della tabella di gara:\n");
            // scanf("%d", &dim_tab);
            // printf("digita la dimensione minima delle navi:\n");
            // scanf("%d",&dim_minima_nave);
            // printf("digita la dimensione massima delle navi:\n");
            // scanf("%d",&dim_massima_nave);
            break;
        case 2:
            dim_tab = 10;
            dim_minima_nave = 2;
            dim_massima_nave = 10;
            gioca(50, nome, dim_tab, dim_minima_nave, dim_massima_nave);
            break;
        default:
            printf("Voce non in elenco, riprova...");
            system("cls");
            break;
        };
    }
    while (r != 0);

    return 0;
}
