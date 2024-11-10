#include <stdio.h>
int main () {
    int a = 0, b = 0, c = 0;
    int max = 0;

    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    printf("Inserisci c: ");
    scanf("%d", &c);

    if(a > b) {
        if (a > c) {
            max = a;
        }
        else if (c > b){
            max = c;
        }
    } else {
        if(b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    printf("max %d\n", max);
}