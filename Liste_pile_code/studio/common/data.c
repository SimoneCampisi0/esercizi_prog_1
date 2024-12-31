#include "data.h"
#include <stdio.h>
#include <string.h>

void printDato (const struct Dato *ptr) {
    printf(" [%d] ", ptr -> value);
}

void copyData(const struct Dato *src, struct Dato *dst){
  memcpy(dst, src, sizeof(struct Dato));  
}