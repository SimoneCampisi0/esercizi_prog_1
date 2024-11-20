/* 

Codificare una funzione in C che prenda in input un array di
caratteri. 
Tale funzione dovr`a restituire la lunghezza della stringa.

*/
#include <stdio.h>
#include <string.h>
int len(char *c) {
    return strlen(c);
}

int len1(char *c) {
    char i = c[0];
    int count = 1;
    while (i != '\0') {
        count+=1;
        i = c[count];
    }
    return count;
}
int main () {
    char *c = "ciaoatutti";
    printf("%d\n", len(c));
    printf("%d\n", len1(c));
}