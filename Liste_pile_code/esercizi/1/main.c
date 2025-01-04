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


void printList(struct Nodo *head) {
    struct Nodo *curr = head;
    while (curr != NULL) {
        printf("[%d] ", curr->value);
        curr = curr -> next;
    }
    printf("\n");
}

void insertNode(struct Nodo **head, int value) {
    struct Nodo *newNode = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNode -> next = NULL;
    newNode -> value = value;

    if(*head != NULL) {
        struct Nodo *curr = *head;
        struct Nodo *prev = NULL;
        while (curr != NULL && (curr -> value < newNode->value)) {
            prev = curr;
            curr = curr -> next;
        }

        if(curr == NULL && prev != NULL) { // Inserimento a fine lista
            prev -> next = newNode; 
        } else if (curr != NULL && prev != NULL) { // Inserimento tra due nodi
            prev -> next = newNode;
            newNode -> next = curr;
        } else if(curr != NULL && prev == NULL) { // Inserimento in testa
            newNode -> next = curr;
            *head = newNode;
        }

    } else 
        *head = newNode;
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
}