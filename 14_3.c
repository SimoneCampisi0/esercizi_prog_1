#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double genDoubleRandom(double a, double b) {
    return a + ((double)rand() / RAND_MAX) * (b - a);
}
int main () {
    srand(time(0));
    int n = 200;
    double *v = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        *(v + i) = genDoubleRandom(10.0, 50.0); 
    }

    const double *p = v;
    for(int i = 0; i < n; i++) {
        if(i % 2 != 0 && i % 3 != 0)
            printf("%lf\n", *(p + i));
    }

    printf("\n\n\n");

    double * const p1 = v;
    for (int i = 0; i < n; i++) {
        if(i % 2 != 0 && i % 3 != 0)
            *(p1 + i) = genDoubleRandom(100.0, 200.0);
        printf("%lf\n", *(p1 + i));
    }

    v = NULL;
    free(v);

}