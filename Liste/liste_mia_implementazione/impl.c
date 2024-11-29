

#include <stdio.h>
#include "single_node.h"

int isEmpty (const struct Nodo *head) {
    return head == NULL;
}

void printList (const struct Nodo *head) {
    //E' const poiché non dobbiamo modificare il valore del dato
    const struct Nodo *current = head;
    while (current != NULL) {
        printf("$d\n", current->d.value);
        current = current -> next;
    }
}

//inserisce il nodo all'inizio della lista. Quindi sempre nell'head
void insertNodo(struct Dato *ptrDato, struct Nodo **head) {
    struct Nodo *nodoDato = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodoDato->d = *ptrDato;
    nodoDato->next = *head;
    *head = nodoDato;
}

void deleteNodo(struct Dato *ptrDato, struct Nodo **head) {
    struct Nodo *current = *head, *previous = NULL;

    while (current != NULL && current->d.value != ptrDato->value) {
        previous = current;
        current = current->next;
    }

    //Se arrivo alla fine della lista, esco
    if (current == NULL) {
        printf("Dato non trovato nella lista\n");
        return;
    }

    //Se il precedente è uguale a NULL dopo l'iterazione, significa che il nodo da eliminare è il primo.
    if (previous == NULL) {
        // Il nodo da eliminare è il primo. Allora la testa punterà al valore successivo a essa, perdendo quindi il riferimento al valore in testa
        *head = current->next;
    } else {
        // Saltiamo il nodo da eliminare:
        /* 
        
        Prima:
        head -> Nodo1 -> Nodo2 -> Nodo3 -> Nodo4
                    (previous)  (current)

        Dopo:
        head -> Nodo1 -> Nodo3 -> Nodo4
                    (previous)  (current->next)
        
        */
        previous->next = current->next;
    }

    free(current); // Libera la memoria del nodo eliminato
}


int main () {

}