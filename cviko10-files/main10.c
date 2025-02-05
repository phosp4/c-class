#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define FILENAME "myfile.txt"
#define FILENAME2 "myfile2.txt"

int main(int argc, char* argv[])
{
    FILE *fs = fopen(FILENAME, "w");
    if (fs == NULL) {
        perror("Cannot write to file!");
        return EXIT_FAILURE;
    }
    
    for (u_int8_t i = 1; i < argc; i++) {
        size_t wnum = fwrite(argv[i], 1, strlen(argv[i]), fs); // napr. "ahoj", 1 (citaj po 1 bajte), 4 (4 krat)
        fwrite("\n", 1, 1, fs);

        printf("%lu bytes written. \n", wnum);
    }

    fclose(fs);

    // reading

    FILE *fs2 = fopen(FILENAME2, "r");
    if (fs2 == NULL) {
        perror("Cannot write to file!");
        return EXIT_FAILURE;
    }

    char one_char = 0;
    while (fread(&one_char, 1, 1, fs2)) { // vypise nulu ak sme na konci suboru
        if (one_char <= 32) {
            printf(" ");
        } else {
            printf("%c", one_char);
        }
    }

    printf("\n");
    printf("Is EOF? %d \n", feof(fs2)); // feof kontroluje end-of-file

    fclose(fs2);

    return EXIT_SUCCESS;
}