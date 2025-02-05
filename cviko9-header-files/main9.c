#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "mylib.h" // relativna cesta z miesta, kde je ulozeny tento subor

int main(int argc, char *argv[]) {
    int s = 0;

    if (sum(1,2,&s) == OPERATION_SUCCESS) {
        printf("Sum is %d \n", s);
    }

    if (argc == 3) {
        printf("TRIMMED: [%s] \n", trim(argv[2]));
    }

    return EXIT_SUCCESS;
}

// musi mat mylib.c rovnaky nazov
// preco nie v zatvorkach
// ako vytvorit .o file