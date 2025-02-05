#include "mylib.h"

uint8_t is_char(const char chr) {
    if (48 <= chr && chr <= 57 || 65 <= chr && chr <= 90 || 97 <= chr && chr <= 122) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t is_printable(const char chr) {
    if (32 < chr && chr < 127) {
        return TRUE;
    } else {
        return FALSE;
    }
}

size_t string_len(const char *str) {
    if (str == NULL) return 0;

    size_t counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}



char* read_from_input(const char *prompt)
{
    // dynamic allocation

    char* out = (char*)malloc(MAX_BUFFER_LEN+1);

    if (out == NULL) {
        printf("Allocation failed!\n");
    return NULL;
    }

    memset(out, 0, MAX_BUFFER_LEN+1);

    printf("%s: ", prompt);
    fflush(stdout);
    
    char *ret = fgets(out, MAX_BUFFER_LEN, stdin);

    if (ret == NULL) {
        printf("Input error");
        return NULL;
    }
    
    return out;
}

word_stat_t get_text_stat(const char *str) {
    uint16_t words_counter = 0;
    uint16_t wchars_counter = 0;
    uint16_t tchars_counter = 0;

    // set it to one to count first word
    uint16_t end_of_word = 1;

    size_t len = string_len(str);

    for (int i = 0; i<len; i++) {
        char chr = str[i];

        // second group
        if (is_char(chr)) {
            wchars_counter++;
        }

        // third group
        if (is_printable(chr)) {
            tchars_counter++;
        }

        /*
            first group
        */
        if (chr == 32) {
            end_of_word = 1;
            continue;
        }

        // if it is a character or number
        if ((end_of_word == 1) && (is_char(chr))) {
            end_of_word = 0;
            words_counter++;
        }
    }

    word_stat_t out = {words_counter, wchars_counter, tchars_counter};
    return out;
}