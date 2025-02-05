#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

struct pole_dlzka {
    char* pole;
    size_t dlzka;
};

struct pole_dlzka find_duplicates(const char *str, size_t length)
{

    char *out_pole = (char*)malloc(length);
    int p = 0;

    memset(out_pole, 0, strlen(out_pole));

    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if ((i != j) && (str[i] == str[j])) {
                // pridaj do pola
                out_pole[p] = str[i];
                p++;
            }
        }
    }

    struct pole_dlzka vystup;
    vystup.pole = out_pole;
    vystup.dlzka = strlen(out_pole);

    return vystup;
}

int main(int argc, char* argv[])
{
    char* string = "aaa";
    struct pole_dlzka test = find_duplicates(string, strlen(string));
    printf("opakuje sa: %s \npocet: %zu \n", test.pole, test.dlzka);

    return EXIT_SUCCESS;
}

// upravit - ak sa opakuje viac ako dvakrat tak to zlyhava, treba nieco ako set alebo cez tu ascii