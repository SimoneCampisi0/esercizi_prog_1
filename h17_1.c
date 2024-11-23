/*

Definire un array di caratteri di lunghezza 15. 
Riempire tale array con caratteri random nel’intervallo [a-z].

Definire un array di caratteri mediante una lista di inizializzazione, che
abbia almeno 5 caratteri. 

Stampare la stringa con una istruzione printf.

Definire un array mediante un inizializzatore che sia un letterale stringa.
Stampare quindi la lunghezza della stringa, e la stringa stessa mediante
una istruzione printf.

Definire un array di caratteri di sola lettura, mediante la definizione di un
puntatore a carattere. Stampare quindi la stringa e la lunghezza della
stringa stessa, mediante una istruzione printf.

*/
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int generateRandom (int a, int b) {
    return rand()%(b - a + 1) + a;
}

int main () {
    // char *c = (char*) calloc(15, sizeof(char)); 
    srand(time(0));
    char *c = calloc(15, sizeof(char));
    if(c == NULL) {
        return 0;
    }

    for(int i = 0; i < 15; i++) {
        *(c + i) = generateRandom(97, 122);
        printf("%c\n", c[i]);
    }
    printf("%s\n", c);

    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%s\n", ch);

    char *letteraleStringa = "Letterale Stringa";
    printf("len: %ld\nvalore: %s\n", strlen(letteraleStringa), letteraleStringa);

    const char *letteraleStringaCostante = "LetteraleStringaCostante";
    printf("len: %ld\nvalore: %s\n", strlen(letteraleStringaCostante), letteraleStringaCostante);
    
    return 0;
}