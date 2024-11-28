#include <stdio.h>
void insertionSort(int arr[], int len) {
    for (int index = 1; index < len; index++) {
        int key = arr[index];
        int position = index;

        //Shift valori più grandi di key a destra
        while(position > 0 && arr[position - 1] > key) {
            //Shift a destra
            arr[position] = arr[position - 1];
            position--;
        }
        arr[position] = key; //Inserimento del valore
    }
}

int main () {
    int arr[] = {35, 44, 2, 7, 10, 16, 108, 3};
    int len = (int) sizeof(arr) / sizeof(int);

    printf("\nPrima dell'InsertionSort: \n");
    for(int i = 0; i < len; i++)
        printf("%d\n", arr[i]);

    insertionSort(arr, len);

    printf("\nDopo l'InsertionSort: \n");
    for(int i = 0; i < len; i++)
        printf("%d\n", arr[i]);
    return 0;
}