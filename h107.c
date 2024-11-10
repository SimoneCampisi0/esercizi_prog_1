/* 
    Estendere l’esercizio precedente in modo da conservare tutti i caratteri 
    in un array di caratteri. 
    Infine, stampare la lunghezza della stringa contenuta in esso 
    con la funzione di libreria strlen.
*/
#include <stdio.h>
int main () {
    char arr[21];
    int i = 0;
    for(char c = 'z'; c >= 'a'; c--) { // Questo è possibile perché z = 122 e a = 97 nella tabella ASCII
    if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            arr[i] = c;
            printf("arr[%d]: %c\n",i, arr[i]);
            i++;
        }
    }
    return 0;
}