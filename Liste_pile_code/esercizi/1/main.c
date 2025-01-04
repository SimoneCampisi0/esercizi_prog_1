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


void deleteNode(struct Nodo **head, int value) {
    struct Nodo *curr = *head;
    struct Nodo *prev = NULL;
    while (curr != NULL && curr -> value != value) {
        prev = curr;
        curr = curr -> next;
    }

    // Se si è trovato il valore da eliminare e si trova tra due nodi
    if(curr != NULL && curr -> next != NULL && prev != NULL) {
        prev -> next = curr -> next;
        free(curr);
    } else if(curr != NULL && curr -> next == NULL && prev != NULL) { // Se il valore è stato trovato ed esso si trova alla fine della lista
        prev -> next = NULL;
        free(curr);
    } else if(curr != NULL && prev == NULL) { // Se il valore trovato si trova in testa
        if(curr -> next != NULL) {
            *head = curr -> next;
            free(curr);
        } else {
            free(*head);
            *head = NULL;
        }
    } else {
        printf("Valore non trovato\n");
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

    // int isEmptyList = isEmpty(head);
    // if(isEmptyList == 1) {
    //     printf("Lista vuota.\n");
    // } else {
    //     printf("Lista non vuota.\n");
    // }

    int value;
    printf("Digita il valore da eliminare: ");
    scanf("%d", &value);
    deleteNode(&head, value);

    printList(head);

}