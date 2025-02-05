#include <string.h>
#include "mylib.h"

uint8_t sum(int a, int b, int *out)
{
    if (out == NULL) {
        return OPEERATION_FAILURE;
    }
    *out = a + b;
    return OPERATION_SUCCESS;
}

// uint8_t is_special(char a)
// {
//     a = (int) a;
//     if (a <= 32) {
//         return 0;
//     } else {
//         return 1;
//     }
// }

// uint8_t trim(char *s)
// {
//     char a = s;
//     while (is_special(a)) {
//         // check if not null
//         if (a == NULL) {
//             break;
//         }
//         // increment
//         *s += 1;
//         a = s;
//     }

//     return OPERATION_SUCCESS;
// }

char *trim(char *str) {
    size_t len = strlen(str);
    int on_word = 0;
    char* first_letter = NULL;

    for (long i = (len-1); i >= 0; i--) {
        if ((str[i] <= 32) && (on_word == 0)) {
            str[i] = 0;
        } else if ((on_word == 1) && (str[i] <= 32)) {
                first_letter = &str[i+1];
                on_word = 0;
        } else if (on_word == 0) {
            on_word = 1;
        }
    }

    return first_letter;
}

// "   ahoj svet    " na "ahoj svet"
// dokoncene s malou pomocou chatgpt - chyby - else if trikrat takto ma byt, == nie =