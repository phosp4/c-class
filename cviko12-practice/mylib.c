/*
    toto treba kompilovat prikazom: "gcc -c mylib.c -o mylib.o"
    vsetky include aj makra maju byt v mylib.h okrem jej samej
    nezabudat alokovat o jedna viac
    nezabudat kontrolovat ci je null alebo nejaky overflow
    pozor na bulharske premenne

    je to v pohode ze je alokovane viac ako potrebujeme?
*/

#include "mylib.h"

char* exclude_letters(const char *word, const char *exclude)
{
    // vytvor priznakove pole
    uint16_t ascii_lookup[CHARS_NUM];

    // prejdi polom exclude
    for (size_t i = 0; i < strlen(exclude); i++) {

        // zaznac si ktore vynachat
        if (ascii_lookup[exclude[i]] == 0) {
            ascii_lookup[exclude[i]] = 1;
        }
    }

    // vytvor vystupny retazec velkosti slova
    // dynamicky ho alokujeme, kedze ho vraciame
    char *out_str = (char*)malloc(strlen(word) + 1); // nezabudat na +1
    if (out_str == NULL) {
        perror("Allocation error!\n");
    }

    // nastav jeho hodnoty na nuly
    memset(out_str, 0, strlen(out_str));

    // vytvor index counter pre vystupny retazec
    uint8_t out_idx = 0;

    // vytvor druhe priznakove pole na kontrolu zapisu
    uint16_t ascii_written[CHARS_NUM];

    // prejdi slovom
    for (size_t i = 0; i <  strlen(word); i++) {

        //  pre kazde slovo pozri ci sa nachadza v priznakovom poli
        //a ci uz nebolo zapisane
        if (ascii_lookup[word[i]] == 0 && ascii_written[word[i]] == 0) {

            // ak nie daj ho do vystupneho retazca
            out_str[out_idx] = word[i];
            ascii_written[word[i]] = 1;
            out_idx++;
        }
    }

    // tu by sa hodilo delokovat nevyuzitu cast alokovanej pamate
    // najskor s calloc a realloc

    // vrat retazec
    return out_str;
}