#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int main () {
    // char ***v = (char ***) calloc(5, sizeof(char **));
    // for (int i = 0; i < 5; i++) {
    //     v[i] = (char**) calloc(10, sizeof(char *));
    //     for (int j = 0; j < 10; j++) {
    //         // v[i][j] = (char *) calloc(50, sizeof(char));
    //         *(*(v + i) + j) = (char *) calloc(50, sizeof(char));
    //         for(int k = 0; k < 50; k++) {
    //             v[i][j][k] = 'c';
    //         }
    //         printf("%s ", v[i][j]);
    //     }
    //     printf("\n");
    // }
    char s[] = "ciao";
    s[2] = 53;
    for(int i = 0; i < strlen(s); i++)
        printf("%c\n",s[i]);
}