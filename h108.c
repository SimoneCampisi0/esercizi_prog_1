/* 

Codificare un programma che stampi le prime N potenze di 2,
dove N `e un parametro scelto dall’utente (input da tastiera).

*/
#include <stdio.h>
int main () {
    int N = 0;
    long pow = 1;
    printf("Digita N: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        if(i != 0) {
            pow *= 2;
            printf("pow[%d]: %ld\n", i+1, pow);
        } else {
            printf("pow[%d]: %ld\n", i+1, pow);
        }
        
    }
    return 0;
}