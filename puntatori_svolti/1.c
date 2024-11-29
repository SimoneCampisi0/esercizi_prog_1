#include <stdio.h>
int main () {
    int num = 2000;
    int k = 20;
    int *p = &num;

    printf("%d\n", *p);

    *p = 34;
    p = &k;
    printf("num: %d\np: %d\n", num, *p);
    return 0;
}