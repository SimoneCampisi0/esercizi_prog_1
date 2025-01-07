#include "queue.h"
#include "single_ref_node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isEmpty(struct Queue *q) {
    return q -> head == NULL;
}

void printQueue(struct Queue *q) {
    if(isEmpty(q)) {
        printf("Coda vuota\n");
        return;
    }

    struct Nodo *curr = q -> head;
    while (curr != NULL) {
        printDato(&(curr -> d));
        curr = curr -> next;
    }
}

int dequeue(struct Queue *q, struct Dato *d) {
    if(isEmpty(q))
        return QUEUE_EMPTY;

    // Copio il valore di q->head->d in *d
    memcpy(d, &(q->head->d), sizeof(struct Dato));
    
    struct Nodo *oldHead = q -> head;
    q -> head = q -> head -> next;

     free(oldHead);

     return 1;
}

void enqueue(struct Queue *q, struct Dato *d) {
    struct Nodo *newNode = (struct Nodo *) malloc(sizeof(struct Nodo));
    memcpy(&(newNode -> d), d, sizeof(struct Dato));

    newNode -> next = NULL;

    if(isEmpty(q)) {
        q -> head = newNode;
        q -> tail = newNode;
        // q->head = q->tail = new_node;
    } else {
        // Assegniamo come successore dell'ultimo nodo il newNode da porre come nodo finale
       (q -> tail)-> next = newNode;
       q -> tail = newNode; 
    }
}