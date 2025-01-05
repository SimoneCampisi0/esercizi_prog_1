/*

Write a C program that converts a singly linked list into a string and returns it.
Test Data and Expected Output :


Linked List: Convert a Singly Linked list into a string
-------------------------------------------------------------
Input the number of nodes: 3
 Input data for node 1 : 10
 Input data for node 2 : 20
 Input data for node 3 : 30

Return data entered in the list as a string:
The linked list: 10 20 30

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Nodo {
    int value;
    struct Nodo * next;
};

void insertNode (struct Nodo **head, int value) {
    struct Nodo *newValue = (struct Nodo *) malloc(sizeof(struct Nodo));
    newValue -> value = value;
    newValue -> next = NULL;

    if(head == NULL) {
        *head = newValue;
        return;
    }

    struct Nodo *curr = *head;
    struct Nodo *prev = NULL;
    while (curr != NULL && curr -> value < value) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr == NULL && prev != NULL) // Inserimento nodo a fine lista
        prev -> next = newValue;
    else if(curr != NULL && prev != NULL) { // Inserimento tra due nodi
        prev -> next = newValue;
        newValue -> next = curr;
    } else { // Se curr != NULL && prev == NULL, quindi inserimento in testa
        newValue -> next = curr;
        *head = newValue; // newValue diventa quindi la testa
    }

}

int isEmpty(struct Nodo *head) {
    if (head == NULL)
        return 1;
    return 0;
}

void printList(struct Nodo *head) {
    if(isEmpty(head)) {
        printf("Lista vuota.\n");
        return;
    }

    struct Nodo *curr = head;
    while (curr != NULL) {
        printf("[%d] ", curr -> value);
        curr = curr -> next;
    }
    printf("\n");
}

int main () {

    struct Nodo *head = NULL;
    int n = 0;
    printf("Digita il numero di nodi da inserire: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Digita il valore da inserire: ");
        scanf("%d", &value);

        insertNode(&head, value);
    }

    printList(head);
    //TODO: iterare lista e concatenarne i valori a una nuova stringa, per poi stamparla

    char *s = (char *) malloc(sizeof(char));
    struct Nodo *curr = head;
    while (curr != NULL) {
        char buffer[50];
        sprintf(buffer, "%d",curr -> value);

        strcat(s, buffer);
        curr = curr -> next;
    }

    int len = strlen(s);
    s = realloc(s, (len+1) * sizeof(char));
    s[len + 1] = '\0';
    printf("Stringa: %s\n ", s);

    return 0;

}