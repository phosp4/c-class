#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

char *mirror_string(const char *str) {
    
}

// int main(int arg, char *argv[]) {

// }

int main() {
    int value = 42;
    int *ptr = &value;
    int **dptr = &ptr;

    printf("test: %p\n", dptr);

    printf("test: %p\n", &value);
    printf("test: %p\n", *dptr);
    printf("test: %p\n", ptr);

    printf("test: %p\n", **dptr);
    printf("test: %d\n", **dptr);

    return EXIT_SUCCESS;
}