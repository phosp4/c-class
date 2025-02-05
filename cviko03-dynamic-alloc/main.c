#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#define MAX_STR_LEN 10

int main(int argc, char *argv[]) {
    char *str = NULL;
    str = (char*)malloc(MAX_STR_LEN+1);

    if (str == NULL) {
        printf("Allocation failed!\n");
        return EXIT_FAILURE;
    }

    // obe prikazy tu robia to iste
    bzero(str, MAX_STR_LEN+1);          // vyplna nulami
    // memset(str, 0, MAX_STR_LEN+1);      // vie vyplnit hocicim

    // tieto styri robia tiez to iste, dereferencia ukazovatela
    // *str = '\0';
    // *str = 0;
    // str[0] = '\0';
    // str[0] = 0;

    *str = 'A';
    str[1] = 'h';
    *(str+2) = 'o';
    str[1+2] = 'j';
    // str[4] = 'j';
    // str[5] = 'j';
    // str[6] = 'v';

    printf("String je %s \n", str);

    // stale treba delokovat pamat
    if (str != NULL) {
        free(str);
    }

    char *str1 = "Ahoj";
    char *str2 = " svet\n";
    // printf("%s",str1+str2); // takato konkatezacia sa v c nepouziva

    return EXIT_SUCCESS;
}