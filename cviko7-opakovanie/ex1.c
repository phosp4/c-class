#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define LIST_LEN 3
#define MAX_STR 122
#define MIN_STR 35

void fill_with_random_chars(char *s)
{
    // alebo inak iterovat?
    for (int i = 0; i < strlen(s); i++) {
        s[i] = rand() % (MAX_STR - MIN_STR + 1) + MIN_STR;
    }

    //printf("%s \n", s);
}

int main(int argc, char* argv[]) {

    // nacitat vstupny zoznam cisel
    // vytvorit pole ukazovatelov dlzky zoznamu cisel
    // pre kazde cislo pola vytvorit pole dlzky toho cisla
    // vlozit tam nahodne vygenerovany retazec (generate random char)

    int numbers[LIST_LEN] = {3, 5, 8};

    char *random_strings[LIST_LEN + 1];

    for (int i = 0; i < LIST_LEN; i++) {
        // pristupime k itemu prvku random_strings
        // ukazovatel na ity prvok pola random_strings
        // to bude prvy prvok
        
        //char *r_string = &random_strings[i];

        char r_string[numbers[i] + 1];
        printf("%lu \n", strlen(r_string));

        // posuvam pole
        fill_with_random_chars(r_string);

        random_strings[i] = r_string;
    }

    // skusobna tlac
    printf("%s \n", random_strings[0]);
    printf("%s \n", random_strings[1]);
    printf("%s \n", random_strings[2]);

    // nedokoncene, su tam nejake chyby

    return EXIT_SUCCESS;
}