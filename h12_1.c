#include <stdio.h>
#include <math.h>
int main () {
    float p = 0.0;
    printf("Digita p: ");
    scanf("%f", &p);

    if(p < 1) {
        printf("Errore, numero minore di 1");
        return 1;
    }

    if (p >= 1) {
        int l = (int)round(p);
        int arr[l];
        for (int i = 0; i < l; i++) {
            arr[i] = i;
        }
        int i = 0;
        while (i < l){
            arr[i] = i;
            i++;
        }

        i = 0;
        do {
            arr[i] = i;
            i++;
        } while(i < l);

        for (int i = 0; i < l; i++) {
            printf("arr[%d]: %d\n",i, arr[i]);
        }

    }
}