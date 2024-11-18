#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double genDoubleRand(double a, double b) {
    return a + ((double)rand() / RAND_MAX) * (b - a);
}
int genIntRand(int a, int b) {
    return rand()%(b - a + 1) + a;
}

int main () {
    srand(time(0));
    double d[10];
    int a[10];

    for (int i = 0; i < 10; i++) {
        d[i] = genDoubleRand(90.0, 1.25);
        *(a + i) = genIntRand(50, 10);

        printf("%lf\n", d[i]);
        // printf("%d\n", *(a + i));
    }

    double *ptr_D = d;
    int *ptr_A = a;

    for(int i = 0; i < 10; i++) {

        if(i%2 != 0) {
            printf("valore: %lf indirizzo: %p\n", *(ptr_D + i), (ptr_D + i));
        } else {
            printf("valore: %d indirizzo: %p\n", ptr_A[i], &ptr_A[i]);
        }

    }

    return 0;
}