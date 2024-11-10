#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main () {
    int N = 0;
    srand(time(0));
    printf("Digita N: ");
    scanf("%d", &N);
    int a = 1;
    int b = 6;

    for(int i = 0; i < N; i++) {
        int d1 = rand()%(b - a + 1) + a;
        int d2 = rand()%(b - a + 1) + a;
        printf("%d ", d1);
        printf("%d", d2);
        printf("\n");
    }

    return 0;
}