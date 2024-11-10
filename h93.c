#include <stdio.h>
int main() {
    char c;
    printf("Digita c:\n");
    scanf("%c", &c);

    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%d\n", c);
            break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            fprintf(stdout, "%c\n", c);
            break;
        case '1':
        case '2':
        case '3': {
            int n = (c - '0') * 10;
            printf("n: %d\n", n);
            break;
        }
    };

    return 0;
}