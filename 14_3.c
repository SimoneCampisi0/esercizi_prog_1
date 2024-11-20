#include <stdio.h>
#include <time.h>
#include <stdlib.h>
double genDoubleRandom(double x, double y) {
    return x + ((double)rand() / RAND_MAX) * (y - x);
}
int main () {
    srand(time(0));
    int N = 200;
    double v[N];
    
    for (int i = 0; i < N; i++) {
        *(v + i) = genDoubleRandom(10, 50);
        // printf("%lf\n", *(v + i));
    }

    //Può cambiare l'indirizzo di memoria
    //Ma NON può cambiare il valore contenuto in esso
    const double *ptr = v;

    //Può cambiare il valore contenuto nell'indirizzo di memoria
    //Ma NON può cambiare l'indirizzo di memoria
    double *const ptr1 = v;
    for (int i = 0; i < N; i++) {
        if(i % 2 != 0 && i % 3 != 0) {
            // printf("before: %lf\n", *(ptr + i));
            ptr1[i] = genDoubleRandom(100, 200);
            // printf("after: %lf\n", *(ptr + i));
        }
    }

    for(int i = 0; i < N; i++) {
        printf("%.100f\n", *(ptr1 + i));
    }

    
    


    return 0;
}