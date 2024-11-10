#include <stdio.h>
int main () {
    int a = 0, b = 0;

    printf("Digita a: ");
    scanf("%d", &a);
    printf("Digita b: ");
    scanf("%d", &b);

    float s = a + b;
    printf("Somma: %.4E\n", s);

    float m = (a + b) / 2.0;
    printf("Media: %.4E\n", m);

    if(a > b) {
        //Per essere stampati in notazione scientifica, int dev'essere convertito in float
        printf("max: %.4E\n", (float)a);
    } else {
        printf("max: %.4E\n", (float)b);
    }

}