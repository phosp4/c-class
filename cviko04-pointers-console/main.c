#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define MAX_BUFFER_LEN 512

void rtrim(char *str) {
    
    // lebo strlen vracia size_t, je to vlastne long bezznamienkovy (unsigned)
    size_t str_len = strlen(str);

    // prepisujeme z konca na nuly pokial nenajdeme text
    for (size_t i = (str_len - 1); i >= 0; i--) {
        
        if (str[i] < 32) {
            str[i] = '\0';
        } else {
            return;
        }
    }
}

// da sa to aj cez ify alebo switch
void remove_vowels(char *str) {
    
    size_t str_len = strlen(str);
    char* vowels = "AaEeIiOoUuÁáÉéíÓóÚúÄä";

    for (size_t i = 0; i < str_len; i++) {
        for (size_t v = 0; v < strlen(vowels); v++) {
            if (str[i] == vowels[v]) {
                str[i] = '_';
            }
        }
    }
}

int main(int arg, char *argv[]) {

    char buffer[MAX_BUFFER_LEN];
    bzero(buffer, MAX_BUFFER_LEN);

    printf("Input string:");
    fflush(stdout); // moze byt ze by sa ten text nezobral

    // ret je len kontrola, ak to bude fungovat tak vrati adresu kde sa uklada ten vstup
    char *ret = fgets(buffer, MAX_BUFFER_LEN, stdin);

    if (ret == NULL) {
        printf("Input error");
        return EXIT_FAILURE;
    }

    // funkcia ktora zmeni samohlasky na _
    remove_vowels(buffer);

    // funkcia ktora vymaze riadiace znaky - ako napr znak noveho riadku
    rtrim(buffer);

    printf("String bez samohlasok je %s, a odstranuje to ascii znaky na konci mensie ako 32 \n", buffer);
    
    return EXIT_SUCCESS;
}