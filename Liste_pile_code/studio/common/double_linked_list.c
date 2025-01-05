#include "double_ref_node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isEmptyDls(const struct Double_ref_nodo *head) {
    if(head == NULL)
        return 1;
    return 0;
}

void insertNodoDls(struct Dato *ptrDato, struct Double_ref_nodo **head) {
    struct Double_ref_nodo *newData = (struct Double_ref_nodo *) malloc(sizeof(struct Double_ref_nodo));
    newData -> next = NULL;
    newData -> prev = NULL;

    copyData(ptrDato, &newData->d);

    if(isEmptyDls(*head)) {
        *head = newData;
        return;
    }

    struct Double_ref_nodo *curr = *head, *prev = NULL;
    // finché curr non è vuoto oppure finché il valore di curr non è maggiore rispetto a newData
    while (curr != NULL && confrontaDati( &(curr->d), &(newData->d) ) < 0) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr != NULL) { // inserimento in testa o fra due nodi
        if(prev == NULL) // allora si inserisce in testa
            *head = newData;
        
        else { // prev != NULL, quindi inserimento tra due nodi
            // collegamento prev <--> newData
            prev -> next = newData;
            newData -> prev = prev;
        }

        // collegamento newData <--> curr
        curr -> prev = newData;
        newData -> next = curr;
    } else { // inserimento in coda, dato che curr == null
        prev -> next = newData;
        newData -> prev = prev;
    }
}

void printListDls(const struct Double_ref_nodo *head) {
    const struct Double_ref_nodo *curr = head;
    printf("list: \n");
    
    while(curr != NULL) {
        printf("[%d] ", curr->d.value);
        curr = curr -> next;
    }
    printf("\n");
}