#include <stdio.h>
#include <float.h>
#include <math.h>

int main () {
    float y = 0.0, x = 0.0;

    do {
        printf("Digita y: ");
        scanf("%f", &y);
        printf("Digita x: ");
        scanf("%f", &x);
    } while (y <= 1 || x >= 1);

    while(1) {
        y = y / x;
        printf("y: %lf\n", y);
        // if(y >= FLT_MAX) {
        if(y == INFINITY) {
            break;
        }
    }
    return 0;
}