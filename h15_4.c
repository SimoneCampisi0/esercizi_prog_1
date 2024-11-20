#include <stdio.h>

int calculateLen(char *c) {
    char i = c[0];
    int count = 1;
    while (i != '\0') {
        count+=1;
        i = c[count];
    }
    return count;
}

int confLessico(char *s1, char *s2) {
    int l1 = calculateLen(s1);
    int l2 = calculateLen(s2);
    int min = l1 <= l2 ? l1 : l2;

    for (int i = 0; i < min; i++) {
        int c1 = s1[i], c2 = s2[i];
        if(c1 < c2) {
            return -1;
        }
        if(c1 > c2) {
            return 1;
        }
    }

    if(l1 < l2) {
        return -1;
    } else if(l1 > l2) {
        return 1;
    } else {
        return 0;
    }

}

int main () {
    char *s1 = "aaaba", *s2 = "aaba";
    printf("Confronto: %d\n", confLessico(s1, s2));
    return 0;
}