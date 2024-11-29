#include <stdio.h>
#include <double_linked_list.h>
#include <stdlib.h>
//Const struct nodo *head poiché il valore non deve cambiare
int isEmptyDls(const struct double_ref_nodo *head) {
    return head == NULL;
}


void insertNodoDls(struct dato *ptrDato, struct double_ref_nodo **head)
{
    struct double_ref_nodo *newNode = (struct double_ref_nodo *) malloc(sizeof(struct double_ref_nodo)); //istanzio il nuovo nodo
    newNode->d = *ptrDato; 
    newNode->next = NULL;
    newNode->prev = NULL;

    if(isEmptyDls(*head)) {
        *head = newNode;
        return;
    }

    struct double_ref_nodo *current = *head;
    //Supponiamo che la lista sia ordinata.
    //Finché il puntatore di current non punta a NULL e il dato puntato dal corrente è 
    while(current != NULL && )
}

int main()
{
    struct double_ref_nodo **head = (struct double_ref_nodo **) malloc(sizeof(struct double_ref_nodo *));

    //aggiungo un nodo
    struct double_ref_nodo *ptrDato = (struct double_ref_nodo *) malloc(sizeof(struct double_ref_nodo));
    struct dato dato;
    dato.value = 10;
    ptrDato->d = dato;

    insertNodoDls(ptrDato, &head);
}
