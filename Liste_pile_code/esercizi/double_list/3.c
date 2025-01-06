/*

    Scrivi un programma in C che, dopo aver preso in input n valori da
    una lista doppiamente concatenata, permetta la rimozione di un valore inserito manualemente.
    Il nodo dovrà essere così composto:

    struct Node {
        double value;
        struct Node *next;
        struct Node *prev;
    };

    I valori di value dovranno essere inoltre generati dinamicamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Node {
    double value;
    struct Node *next;
    struct Node *prev;
};

void insertNode (struct Node **head, struct Node *newNode) {
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    // itero la lista
    struct Node *curr = *head, *prev = NULL;
    while (curr != NULL && (curr -> value < newNode -> value)) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr == NULL && prev != NULL) { // Inserimento a fine lista
        prev -> next = newNode;
        newNode -> prev = prev;
    } else if(curr != NULL && prev != NULL) { //Inserimento tra due nodi
        prev -> next = newNode;
        newNode -> prev = prev;
        newNode -> next = curr;
        curr -> prev = newNode;
    } else if(curr != NULL && prev == NULL) { // Inserimento in testa
        newNode -> next = curr;
        curr -> prev = newNode;
        *head = newNode;
    }
}

double genDoubleRandom(int a, int b) {
    return a + ((double) rand() / RAND_MAX) * (b - a);
}

int isEmpty(const struct Node *head) {
    return head == NULL;
}

void printList(const struct Node *head) {
    if(isEmpty(head)) {
        printf("lista vuota.\n");
        return;
    }

    const struct Node *curr = head;
    while (curr != NULL) {
        printf("[%lf] ", curr->value);
        curr = curr -> next;
    }
    printf("\n");
}

int deleteNode(struct Node **head, double dataToRemove) {
    struct Node *curr = *head;

    while (curr != NULL && (fabs(curr->value - dataToRemove) > 0.00001)) {
        curr = curr -> next;
    }

    if(curr == NULL) {
        printf("Dato non trovato\n");
        return 0;
    }

    if(curr -> prev != NULL && curr -> next != NULL) { // eliminazione tra due nodi
        struct Node *prev = curr -> prev;
        struct Node *next = curr -> next;

        prev->next = next;
        next -> prev = prev;

        free(curr);
        curr = NULL;

        return 1;
    } else if(curr -> prev != NULL && curr -> next == NULL) { // eliminazione dato fine lista
        struct Node *prev = curr -> prev;
        prev -> next = NULL;
        free(curr);
        curr = NULL;

        return 1;
    } else if(curr -> prev == NULL && curr -> next != NULL) { // eliminazione dato inizio lista
        struct Node *next = curr -> next;
        next -> prev = NULL;
        *head = next;
        free(curr);
        curr = NULL;

        return 1;

    } else { // caso in cui curr coincide con head
        free(curr);
        curr = NULL;
        *head = NULL;

        return 1;
    }

    return 0;
}

void deleteList(struct Node **head) {
    if(isEmpty(*head)) {
        printf("lista vuota\n");
        return;
    }

    struct Node *curr = *head;
    while (curr != NULL) {
        struct Node *next = curr -> next;
        free(curr);
        curr = next;
    }
    
    *head = NULL;
}

int main () {
    srand(time(0));
    int n = 0;
    struct Node *head = NULL;

    printf("Digita lunghezza lista: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode -> value = genDoubleRandom(1, 100);
        newNode -> next = NULL;
        newNode -> prev = NULL;

        insertNode(&head, newNode);
    }

    printList(head);

    int r = 0;
    do {
        printf("1 - elimina elemento\n2 - stampa lista\n3 - elimina tutta la lista\n0 - esci\n");
        scanf("%d",&r);
        switch(r) {
            case 0:
                printf("Sto uscendo...\n");
                break;
            case 1:
                double dataToRemove;
                printf("Digita il valore da eliminare: ");
                scanf("%lf", &dataToRemove);

                if(deleteNode(&head, dataToRemove))
                    printf("Elemento [%lf] eliminato correttamente.\n", dataToRemove);
                
                break;
            case 2:
                printf("\n\n\n\n");
                printList(head);
                break;

            case 3:
                deleteList(&head);
                break;
            default:
                printf("Voce non in elenco, riprova...\n");
                break;
        };

    } while(r != 0);

    return 0;
}