#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#define FILENAME "myfile3.txt"
#define MAX_BUFFER_LEN 512

int main(int argc, char* argv[])
{

    /*
        reading from terminal
    */

    char buffer[MAX_BUFFER_LEN];
    memset(buffer, 0, MAX_BUFFER_LEN);

    printf("Zadajte vstup na zapis: ");
    fflush(stdout);
    char *ret = fgets(buffer, MAX_BUFFER_LEN, stdin);
    if (ret == NULL) { printf("Input error"); return EXIT_FAILURE; }

    /*
        replacing spaces with tabs
    */
    int buffer_len = strlen(buffer);

        // odstranenie znaku noveho riadku z konca
    if (buffer[buffer_len - 1] == '\n') {
        buffer[buffer_len - 1] = '\0';
    }

    for (int i = 0; i < buffer_len; i++) {
        if (buffer[i] == 32) {
            buffer[i] = 9;
        }
    }

    /*
        writing to the file
    */

    FILE *fs = fopen(FILENAME, "w");
    if (fs == NULL) {
        perror("Cannot write to file %s!" FILENAME);
        return EXIT_FAILURE;
    }
    
    size_t wnum = fwrite(buffer, 1, strlen(buffer), fs);
    printf("%lu bytes written. \n", wnum);

    fclose(fs);

    return EXIT_SUCCESS;
}