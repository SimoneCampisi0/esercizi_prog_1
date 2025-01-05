/* 

Write a program in C to create a singly linked list of n nodes and display it in reverse order.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

 Data entered in the list are :                                                                               
 Data = 5                                                                                                     
 Data = 6                                                                                                     
 Data = 7                                                                                                     
                                                                                                              
 The list in reverse are :                                                                                    
 Data = 7                                                                                                     
 Data = 6                                                                                                     
 Data = 5 

*/
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int value;
    struct Nodo * next;
};

void insertNode(struct Nodo **head, int value) {
    struct Nodo *newNode = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNode -> next = NULL;
    newNode -> value = value;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Nodo *curr = *head;
    struct Nodo *prev = NULL;
    while (curr != NULL && (curr -> value < newNode -> value)) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr == NULL && prev != NULL) { // Inseriemento a fine lista
        prev -> next = newNode;
    } else if(curr != NULL && prev != NULL) { // Inserimento tra due nodi
        prev -> next = newNode;
        newNode -> next = curr; // Perché newNode->value < curr->value
    } else { //Altrimenti, se curr != NULL && prev == NULL, quindi inserimento in testa
        newNode -> next = curr;
        *head = newNode;
    }
}

int isEmpty(struct Nodo *head) {
    if(head == NULL) {
        return 1;
    }
    return 0;
}

void printList(struct Nodo *head) {
    if(!isEmpty(head)) {
        struct Nodo *curr = head;
        while (curr != NULL) {
            printf("[%d] ", curr->value);
            curr = curr -> next;
        }
        printf("\n");
    } else {
        printf("Lista vuota.\n");
    }
}


void printListReverse(struct Nodo *head) {
    int i = 0;
    int capacity = 1;
    if(isEmpty(head)) {
        printf("Lista vuota.\n");
        return;
    }

    struct Nodo *curr = head;
    int *arr = (int *) malloc(sizeof(int) * capacity);
    while (curr != NULL) {
        if(i != 0)
            arr = realloc(arr, capacity * sizeof(int));

        *(arr + i) = curr->value;
        curr = curr -> next;
        i++;
        if(curr) {
            capacity++;
        }
    }

    for (int j = capacity - 1; j >= 0; j--) {
        printf("[%d] ", *(arr + j));
    }
}

int main () {

    int n = 0;
    struct Nodo *head = NULL;

    printf("Digita n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int value = 0;
        printf("\nDigita il valore: ");
        scanf("%d", &value);

        insertNode(&head, value);
    }

    printList(head);

    printf("\nREVERSE:\n\n");

    printListReverse(head);
    
    return 0;

}