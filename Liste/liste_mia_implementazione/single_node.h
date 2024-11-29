#ifndef SINGLE_NODE_H
    #define SINGLE_NODE_H
    #include "data_nodo.h"
    struct Nodo {
        struct Dato d;
        struct Nodo *next;
    };
#endif