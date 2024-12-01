#include <stdio.h>
#include <stdlib.h>
void func(double *V[][10]) {
    // Puoi accedere agli elementi di V
    V[0][0] = NULL; // Esempio di modifica
}

int main() {
    double *stack_matrix[5][10]; // Matrice allocata nello stack
    func(stack_matrix);         // Passaggio valido
    return 0;
}
