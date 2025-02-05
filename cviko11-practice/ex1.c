#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

// este doplnit kontrola prazdnych retazcov
char *concatenate_strings(const char *str1, const char *str2)
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    char *str3 = (char*)malloc(str1_len+str2_len+1);

    if (str3 == NULL) {
        perror("Allocation error. \n");
        return NULL;
    }

    memset(str3, 0, str1_len+str2_len+1);
    memcpy(str3, str1, strlen(str1));
    memcpy(str3+str1_len, str2, strlen(str2)); // alebo strncpy, strcpy

    return str3;
}

int main(int argc, char* argv[])
{
    char *s1 = "ahoj ";
    char *s2 = "svet";
    char *test = concatenate_strings(s1, s2);
    printf("vstup 1: %s \nvstup 2: %s \nvystup: %s \n", s1, s2, test);

    free(test);
}