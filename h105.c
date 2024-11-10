/*
    Codificare in linguaggio C un programma che stampi 
    a ritroso (al contrario) i numeri positivi pari minori o uguali a mille; 
    inoltre le iterazioni finiscono se la somma dei numeri precedentemente stampati è maggiore o uguale a centomila
*/
#include <stdio.h>
int main () {
    int s = 0;
    for (int i = 1000; i > 0; i=i-2) {
        printf("%d\n", s);
        s+=i;
        if(s >= 100000) {
            break;
        }
    }
    return 0;
}