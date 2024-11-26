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
    double x = (x / 2 + 1234.1234);
    int s = rand () % 100.0;
}