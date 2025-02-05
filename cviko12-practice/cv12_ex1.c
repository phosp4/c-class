/*
    toto treba kompilovat prikazom: "gcc cv12_ex1.c mylib.c -o cv12_ex1"
    (teda aj ta mylib.c tam musi byt zahrnuta)
*/

#include <stdio.h> // kvoli printf
#include <stdlib.h> // kvoli exit success a failure

#include "mylib.h" // relativna cesta z miesta, kde je ulozeny tento subor

int main(int argc, char* argv[])
{
    char* test = exclude_letters("mississipi", "maska");
    if (test == NULL)  {
        perror("output is null!");
        return EXIT_FAILURE;
    }

    printf("Output string: %s \n",test);

    free(test);

    return EXIT_SUCCESS;
}