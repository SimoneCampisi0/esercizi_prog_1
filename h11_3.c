#include <stdio.h>
int main () {
    float a = 2.0;
    int b = 2;

    printf("1: %lf\n", a / 0); //Dato che è float, il numero restituisce inf seguendo lo standard IEEE 754
    printf("2: %d\n", b / 0); //Floating point exception (core dumped) -> 
    // Dato che non è un float, non supporta il tipo Inf, quindi viene considerata non valida
    // e restituisce FPE
    
    return 0;
}