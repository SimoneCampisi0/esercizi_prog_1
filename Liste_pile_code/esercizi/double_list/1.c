/*

Write a program in C to create and display a doubly linked list.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 2
Input data for node 2 : 5
Input data for node 3 : 8
Expected Output :

 Data entered on the list are :                                                                               
 node 1 : 2                                                                                                   
 node 2 : 5                                                                                                   
 node 3 : 8 

*/


#include <stdio.h>
#include <stdlib.h>

struct Data {
    int value;
};

struct Node {
    struct Data data;
    struct Node * next;
    struct Node * prev;
};

void printList(const struct Node *head) {
    const struct Node *curr = head;
    while (curr != NULL) {
        printf("[%d] ", curr->data.value);
        if(curr -> next != NULL)
            printf(" -> ");
        curr = curr -> next;
    }
    printf("\n");
}

void insertNode(struct Node **head, int value) {
    struct Data d;
    d.value = value;

    struct Node *node = (struct Node *) malloc (sizeof(struct Node));
    node -> data = d;
    node -> next = NULL;
    node -> prev = NULL;

    if(*head == NULL) {
        *head = node;
        return;
    }

    struct Node *curr = *head, *prev = NULL;
    while (curr != NULL && (curr -> data.value < node -> data.value)) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr == NULL && prev != NULL) { // inserimento a fine lista
        prev -> next = node;
        node -> prev = prev;
    } else if(curr != NULL && prev != NULL) { // inserimento tra due nodi
        prev -> next = node;
        node -> prev = prev;
        node -> next = curr;
        curr -> prev = node;
    } else if(curr != NULL && prev == NULL) { // inserimento in testa
        node -> next = curr;
        curr -> prev = node;
        *head = node;
    }
    
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

    printList(head);

    return 0;
}