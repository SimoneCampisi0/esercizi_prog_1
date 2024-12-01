#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int genIntRand(int a, int b) {
    return rand() % (b - a + 1) + a;
}
// int genIntRand(int a, int b) {
//     return rand() % b;
// }
int media(int n, int (*m)[n]) {
    double m1 = 0.0, m2 = 0.0;
    for(int i = 0; i < n; i++) {
        m1+=m[i][i];
    }
    int c = 0;
    for(int i = n - 1; i >=0; i--){
        m2+=m[c][i];
        c++;
    }
    m1 = m1 / n;
    m2 = m2 / n;
    return abs(m1 - m2);
}
int main () {
    srand(time(0)); 
    int n = 5;
    int m[n][n];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            *(*(m + i) + j) = genIntRand(0, 100);
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\nValore: %d\n", media(n, m));
    return 0;
}