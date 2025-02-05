#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define MAX_POINTER_ARRAY 10
#define MAX_STR_LEN 10

// argc je pocet prvkov v argv
int main(int argc, char* argv[]) {

    // // v tomto pripade kompilator sa postara o spravnu dlzku
    // char my_array[] = "Ahoj svet";
    // char **p_my_array = &my_array;

    // // toto vracia prve pismeno, ale vraj by nemalo
    // printf("First letter: %c \n", *p_my_array);
    // printf("First letter: %c \n", p_my_array[0]);

    // for (uint8_t i = 0; i < argc; i++) {
    //     printf("Argument %u: %s \n", i, argv[i]);
    // }

    char *parray[MAX_POINTER_ARRAY];

    char *str01 = (char*)malloc(MAX_STR_LEN);

    if(str01 == NULL) {
        perror("Allocation error. \n");
        return EXIT_FAILURE;
    }
    memset(str01, 0, MAX_STR_LEN);
    strcpy(str01, "ahoj svet");

    parray[0] = str01;

    // toto vsetko robi to iste
    printf("output: %c \n", *(parray[0]));
    printf("output: %c \n", (*parray)[0]);
    printf("output: %c \n", parray[0][0]);
    printf("output: %c \n", **parray);

    printf("---\n");

    // toto vsetko tiez robi to iste
    printf("output: %c \n", *(parray[0] + 1));
    printf("output: %c \n", (*parray)[1]);
    printf("output: %c \n", parray[0][1]);
    printf("output: %c \n", *(*parray + 1));

    printf("---\n");

    // printf("output: %u \n", parray[1][1]);

    return EXIT_SUCCESS;
}