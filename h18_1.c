/*

Codificare una funzione per il calcolo del fattoriale
con approccio iterativo.

Fattoriale: 5! = 5 * 4 * 3 * 2 * 1; 
*/
#include <stdio.h>
int main () {
    int n = 0;
    long int f = 0;
    printf("Digita n: ");
    scanf("%d",&n);
    f = n;
    for(int i = n - 1; i >= 1; i--) {
        f = f * i;
    }
    printf("f: %ld\n", f);
    return 0;
}