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
    copyData(ptrDato, &newNode->d);

    /* Se la testa è vuota, allora il nodo da inserire sarà inserito in essa*/
    if(isEmpty(*head)){
        *head = newNode;
        return;
    }

    struct Nodo *current = *head;
    struct Nodo *previous = NULL;

     /* Il ciclo avanza nella lista finché:
        -il nodo 'current' non è vuoto, ovvero si è raggiunta la fine della lista
        -i dati del nodo corrente sono MINORI rispetto ai dati del nuovo nodo (confrontaDati da output < 0) 
    */
   while(current != NULL && confrontaDati(&(current->d), &(newNode->d))<0){
			previous = current; 
			current=current->next;
    }

    /* Se il nodo precedente è diverso da NULL, allora significa che 
        ci troviamo in mezzo o in fondo alla lista.
        Il successivo del nodo precedente diventa il nostro nodo,
        perché previus < nuovo_nodo < current
    */
    if(previous != NULL)
			previous->next = newNode; 
    /* Altrimenti, se previous è rimasto NULL, significa che il nodo current 
        sarà maggiore o uguale del nuovo_nodo, che dev'essere quindi inserito in testa.
     */
    else
        *head = newNode;

    /* Successivamente, il next del nuovo nodo viene impostato al
     vecchio valore current */
    if(current != NULL)
        newNode->next = current;
}