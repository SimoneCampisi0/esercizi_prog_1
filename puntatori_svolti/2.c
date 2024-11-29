#include <stdio.h>
int main () {
    int v [] = {1, 2, 3, 4, 5};
    int * ptr1 = v;
    int * ptr2 = &v[4]; //Punta al dato 5

    printf("%p\n", (ptr1));
    printf("%p\n", (ptr1 + 1));
    printf("%d\n", *(ptr1));
    printf("%d\n", *(ptr1 + 1));

    printf("\n%d\n", *(ptr2));
    printf("%d\n", *(ptr2 - 1));

    ptr2-=2;
    printf("\n%d\n", *ptr2);

    return 0;
}