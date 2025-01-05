#include <stdio.h>
#include <stdlib.h>

#include "common/double_linked_list.h"
#include "common/double_ref_node.h"

int main () {
    struct Double_ref_nodo *head = NULL;

    struct Dato newDate;

    int inputData[] = {10,20,30,40,50};

    for(int i = 0; i < 5; i++) {
        printf("Provo ad aggiungere: [%d]\n", *(inputData + i));
        newDate.value = *(inputData + i);
        insertNodoDls(&newDate, &head);
    }

    printListDls(head);

    return 0;
}