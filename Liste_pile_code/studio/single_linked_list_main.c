#include "common/single_linked_list.h"
#include "common/single_ref_node.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int genIntRandom (int a, int b) {
    return rand()%(b - a + 1) + a;
}

int main () {
    srand(time(0));
    struct Nodo * head = NULL;
    struct Dato example;

    int lastNodeValue = 0;
    for (int i = 0; i < 5; i++) {
        example.value = genIntRandom(1, 10);
        //TODO: terminare studio e implementazione metodo insertNodo.
        lastNodeValue = example.value;
        insertNodo(&example, &head);
    }
    
    printList(head);

    struct Nodo *ptr = (struct Nodo *) malloc(sizeof(struct Nodo));
    ptr->d.value = lastNodeValue;
    deleteNodo(ptr, &head);

    printf("\n\n\n");

    printList(head);

    return 0;

}