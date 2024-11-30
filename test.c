#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//5 * 4 * 3 * 2 * 1
long fat(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fat(n - 1); //chiamata ricorsiva
}
int main () {
    int x = 5, y = 10;
    int *p = &x, *q = &y;
    p = q;
    *p = *p + 5;
    printf("%d %d", x, y);



}