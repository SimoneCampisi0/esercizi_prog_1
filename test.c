#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int **fun(int k) {
//     // int *arr = malloc(sizeof(double) * k);
//     // for (int i = 0; i < k; i++) {
//     //     arr[i] = 2*i;
//     // }
//     int **arr = (int **) calloc(10, sizeof(int *));
//     return arr;
// }

// int main () {
//     int **arr = fun(10);
//     for (int i = 0; i < 10; i++) {
//         *(arr + i) = malloc(sizeof(int) * 10);
//         for(int j = 0; j < 10; j++) {
//             *(*(arr + i) + j) = rand()%(10 - 5 + 1) + 5;
//         }
//     }
    
//     for (int i = 0; i < 10; i++) {
//         for (int j = 0; j < 10; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }


void test (int *x) {
    *x = 10;   
}

int main () {
    int x = 5;
    test(&x);

    printf("%d\n",x);
    return 0;
}