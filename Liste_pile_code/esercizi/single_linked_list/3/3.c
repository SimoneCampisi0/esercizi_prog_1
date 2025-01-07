/* 

Input: linked list: 1->2->3->4->5
Output: 3 
Explanation: There are 5 nodes in the linked list and there is one middle node whose value is 3.


Input: linked list = 10 -> 20 -> 30 -> 40 -> 50 -> 60
Output: 40
Explanation: There are 6 nodes in the linked list, 
so we have two middle nodes: 30 and 40, but we will return the second middle node which is 40.

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Node {
    int value;
    struct Node *next;
};

int genIntRandom(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int isEmptyList(const struct Node *head) {
    return head == NULL;
}

void printList(const struct Node *head) {
    if(isEmptyList(head)) {
        printf("lista vuota.\n");
        return;
    }

    const struct Node *curr = head;
    while (curr != NULL) {
        printf("[%d] ", curr -> value);
        curr = curr -> next;
    }
    printf("\n");
}

void insertNode(struct Node **head, int value) {
    struct Node *newValue = (struct Node *) malloc(sizeof(struct Node));
    newValue -> value = value;
    newValue -> next = NULL;

    if(*head == NULL) {
        *head = newValue;
        return;
    }

    struct Node *curr = *head, *prev = NULL;
    while (curr != NULL && (curr -> value < newValue -> value)) {
        prev = curr;
        curr = curr -> next;
    }

    if(curr == NULL) { // inserimento in coda, esiste almeno un prev
        prev -> next = newValue;
    } else if(prev != NULL) { // inserimento tra due nodi
        prev -> next = newValue;
        newValue -> next = curr;
    } else { // inserimento in testa - prev == NULL
        newValue -> next = curr;
        *head = newValue;
    }

}

int getMiddleNode(const struct Node *head) {
    int n = 0;
    const struct Node *curr = head;

    while (curr != NULL) {
        n++;
        curr = curr -> next;
    }

    n = (n / 2) + 1;
    
    int i = 1;
    curr = head;
    while (curr != NULL && i != n) {
        curr = curr -> next;
        i++;
    }

    int middleValue = curr -> value;
    return middleValue;
}

int main () {
    srand(time(0));
    int n = 0;
    struct Node *head = NULL;

    printf("Digita lunghezza della lista: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value = genIntRandom(1, 1000);
        insertNode(&head, value);
    }

    printList(head);

    int middleValue = getMiddleNode(head);
    printf("middleValue: [%d]\n", middleValue);

    return 0;
}