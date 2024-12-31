#ifndef NODE_H
    #define NODE_H
    #include "data.h"
    struct Nodo {
        struct Dato d;
        struct Nodo * next; //nodo successivo
    };
#endif