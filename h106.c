/*
    Codificare in linguaggio C un programma che stampi a ritroso
    la sequenza di caratteri da ’a’ a ’z’, ma non le vocali. 
    Codificare due versioni differenti nelle quali si fa uso del costrutto
    for e del costrutto while rispettivamente.
*/
#include <stdio.h>
int main () {
    // for(char c = 'z'; c >= 'a'; c--) { // Questo è possibile perché z = 122 e a = 97 nella tabella ASCII
    //     if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
    //         printf("c: %c\n",c);
    //     }
    // }

    char c = 'z';
    while (c >= 'a') {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            printf("c: %c\n",c);
        }
        c--;
    }
}