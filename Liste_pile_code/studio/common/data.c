#include "data.h"
#include <stdio.h>
#include <string.h>

void printDato (const struct Dato *ptr) {
    printf(" [%d] ", ptr -> value);
}

void copyData(const struct Dato *src, struct Dato *dst){
  memcpy(dst, src, sizeof(struct Dato));  
}

int confrontaDati(const struct Dato *d1, const struct Dato *d2){
  if((*d1).value > (*d2).value)
    return 1;
  else if (d1->value < d2->value)
    return -1;
  return 0;
}