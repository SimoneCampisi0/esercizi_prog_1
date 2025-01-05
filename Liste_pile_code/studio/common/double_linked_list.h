#ifndef DOUBLE_LIST_H
    #define DOUBLE_LIST_H    
    #include "double_ref_node.h"

    int isEmptyDls(const struct Double_ref_nodo *head);
    void printListDls(const struct Double_ref_nodo *head);
    void insertNodoDls(struct Dato *ptrDato, struct Double_ref_nodo **head);
    void deleteNodoDls(struct Dato *ptrDato, struct Double_ref_nodo **head);
    
#endif