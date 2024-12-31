#include <stdio.h>
#include "single_ref_node.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int isEmpty(const struct Nodo *head) {
    return head == NULL;
}

void printList(const struct Nodo *head) {
    const struct Nodo *ptr = head;

    while (ptr != NULL) {
        printDato(&(ptr -> d));
        ptr = ptr -> next;
    }

}

void insertNodo(struct Dato *ptrDato, struct Nodo **head) {
    struct Nodo *newNode = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNode->next = NULL;
    copyData(&newNode->d, ptrDato);

    if(isEmpty(*head)){
        *head = newNode;
        return;
    }
}