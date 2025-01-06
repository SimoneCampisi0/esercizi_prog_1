/* 

Write a program in C to create a doubly linked list and display it in reverse order.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 2
Input data for node 2 : 5
Input data for node 3 : 8
Expected Output :

 Data in reverse order are :                                                                                  
 Data in node 1 : 8                                                                                           
 Data in node 2 : 5                                                                                           
 Data in node 3 : 2 

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node * next;
    struct Node * prev;
};

void insertNode (struct Node **head, int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode -> value = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

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

int isEmpty(const struct Node *head) {
    return head == NULL;
}

void printList(const struct Node *head) {
    const struct Node *curr = head;
    while (curr != NULL) {
        printf("[%d] ", curr->value);
        curr = curr -> next;
    }
    printf("\n");
}

void printListReverse(const struct Node *head) {
    if(isEmpty(head)) {
        printf("lista vuota.\n");
        return;
    }

    const struct Node *curr = head;
    
    // Raggiungo la fine della lista
    while (curr -> next != NULL) {
        curr = curr -> next; 
    }

    // E itero a ritroso da li
    while (curr != NULL) {
        printf("[%d] ", curr -> value);
        curr = curr -> prev;
    }

    printf("\n");
}

int main () {

    int n = 0;
    struct Node *head = NULL;

    printf("Quanti nodi vuoi inserire? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value = 0;
        printf("Digita valore: ");
        scanf("%d", &value);

        insertNode(&head, value);
    }

    printf("Stampo lista normale:\n");
    printList(head);

    printf("Stampo lista reverse:\n");
    printListReverse(head);

    return 0;
}