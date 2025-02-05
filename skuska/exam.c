#include "mylib.h"

int main(int argc, char *argv[]) {
    // POSTUP:
    // precitaj z terminalu
    // vytvor si counters
    // prechadzaj vstupom a pridavaj do counters
    // vytvor strukturu (dynamicky?), dopln tam data
    // vrat strukturu

    // todo ci ascii mozu byt napevno
    // odskusat edgecases - "" atd
    // rozdelit to do kniznic
    // rtrim alebo nieco take?

    char* text = read_from_input("Insert some text: ");
    word_stat_t t = get_text_stat(text);
    printf("%d, %d, %d \n", t.num_words, t.num_wchars, t.num_tchars);

    if (text != NULL) {
        free(text);
    }

    return EXIT_SUCCESS;
}