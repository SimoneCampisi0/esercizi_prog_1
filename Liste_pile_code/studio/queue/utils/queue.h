#ifndef QUEUE_H
    #define QUEUE_H
    #include "single_ref_node.h"

    #define QUEUE_EMPTY -1
    
    struct Queue {
        struct Nodo * head;
        struct Nodo * tail;
    };

    /* 

        Inserisce un nuovo nodo nella coda.
        Copia, nel nuovo nodo, il dato puntato
        dal parametro d
    
    */
    void enqueue(struct Queue *q, struct Dato *d);

    /*

        Rimuove il nodo presente nella testa.
        Copia il dato presente nel nodo rimosso
        nell'area di memoria puntata da d.

        Restituisce QUEUE_EMPTY se la coda è vuota.

    */
    int dequeue(struct Queue *q, struct Dato *d);

    /*
    
    Visita l'intera coda, dalla testa fino alla fine e
    stampa tutti gli elementi della coda.
    
    */
    void printQueue(struct Queue *q);


    /*
    
    La coda è vuota se i puntatori head e tail sono NULL. Restituisce:
        -0 se la coda non è vuota
        -!= 0 se è vuota
    
    */
    int isEmpty(struct Queue *q);

#endif