#ifndef __MYLIB__
#define __MYLIB__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#define OPERATION_SUCCESS 1
#define OPEERATION_FAILURE 0

#define MAX_BUFFER_LEN 256
#define TRUE 1
#define FALSE 0


typedef struct {
    uint16_t num_words;
    uint16_t num_wchars;
    uint16_t num_tchars;
} word_stat_t;

uint8_t is_char(const char chr);
uint8_t is_printable(const char chr);
size_t string_len(const char *str);
char* read_from_input(const char *prompt);
word_stat_t get_text_stat(const char *str);

#endif