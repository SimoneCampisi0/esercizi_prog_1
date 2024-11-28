#include <stdio.h>
#include <stdbool.h>
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {           // Ciclo esterno
        for (int j = 0; j < n - i - 1; j++) {   // Ciclo interno
            if (array[j] > array[j + 1]) {
                // Scambia array[j] e array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void swap(int *arr, int i, int i_1) {
    if(*(arr + i) > *(arr + i_1)) {
        int temp = arr[i];
        arr[i] = arr[i_1];
        arr[i_1] = temp;
    }
}

void bubbleSortOttimizzato(int arr[], int n) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                swap(arr, i, i+1);
                swapped = true;
            }
        }
    }
}

int main () {
    int arr[] = {22, 35, 1, 2, 101, 30, 76, 5};
    int len = (int) sizeof(arr) / sizeof(int);
    printf("len: %d\n", len);
    // bubbleSort(arr, len);
    bubbleSortOttimizzato(arr, len);

    for(int i = 0; i < len - 1; i++) {
        printf("%d\n", arr[i]);
    }
}