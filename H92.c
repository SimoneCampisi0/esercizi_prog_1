#include <stdio.h>
int main () {
    int a = 0, b = 0, c = 0, k = 0;

    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    printf("Inserisci c: ");
    scanf("%d", &c);

    printf("Inserisci k: ");
    scanf("%d", &k);

    if(a != c && k > 8) {
        b = a + c;
    }
    else if(a == c && k < 8) {
        a = c - b;
    }
    else {
        int s = (a + b + c) / 3;
        printf("%d", s);
    }

    a = 0, b = 0, c = 0;

    return 0;
}