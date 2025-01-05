#ifndef DOUBLE_REF_NODE_H
    #define DOUBLE_REF_NODE_H
    #include "data.h"
    struct Double_ref_nodo {
        struct Dato d;
        struct Double_ref_nodo * prev;
        struct Double_ref_nodo * next;
    };
#endif