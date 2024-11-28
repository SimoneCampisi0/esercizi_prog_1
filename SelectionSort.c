#include <stdio.h>
#include <stdlib.h>
void swap(int *arr, int min, int index) {
    int temp = arr[min];
    arr[min] = arr[index];
    arr[index] = temp;
}

void selectionSort(int *arr, int size) {
    int min = 0;
    //Ciclo esterno: percorre l'array fino al peunultimo elemento
    //i rappresenterà l'indice dell'inizio della parte non ordinata
    //A ogni iterazione, l'algoritmo sposta un elemento dalla parte non ordinata
    //alla parte ordinata
    for (int i = 0; i < size - 1; i++) {
        min = i;
        //Ciclo interno: cerca il valore minimo nella parte
        //non ordinata nell'array. j rappresenta l'indice dell'elemento
        //della parte non ordinata.
        //L'indice parte da j = i + 1 perché:
        //Parte ordinata: da 0 a i;
        //Parte non ordinata: da i + 1 a size - 1
        for (int j = i + 1; j < size; j++) {
            // Se l'elemento corrente è più piccolo di quello
            //memorizzato come minimo, allora l'indice min
            //si aggiornerà con l'elemento corrente
            if(arr[j] < arr[min]) 
                min = j;
        }
        swap(arr, min, i);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}

int main () {
    int *arr = (int *) malloc(sizeof(int));
    int size = 0, input = 0;
    char c;
    do {
        printf("Digita un numero da inserire nell'array: ");
        scanf("%d", &input);
        size++;

        //Rialloco l'array con la dimensione aumentata di uno
        arr = (int *) realloc(arr, size * sizeof(int));
        arr[size - 1] = input;
        printf("Vuoi aggiungere un altro numero? (y/n): ");
        scanf(" %c", &c);
    } while(c == 'y');

    printf("\n\n\nPRIMA DELL'ORDINAMENTO:\n");
    printArray(arr, size);

    printf("\n\n\nDOPO L'ORDINAMENTO: \n")
    selectionSort(arr, size);
    printArray(arr, size);
}