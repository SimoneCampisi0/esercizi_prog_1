#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "single_ref_node.h"

// Prototipi (dichiarazioni) delle funzioni
int isEmpty(const struct Nodo *head);
void printList(const struct Nodo *head);
void insertNodo(struct Dato *ptrDato, struct Nodo **head);

#endif
