#ifndef __MYLIB__
#define __MYLIB__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "mylib.h"

#define CHARS_NUM 256

#define OPERATION_SUCCESS 1
#define OPEERATION_FAILURE 0

char* exclude_letters(const char *word, const char *exclude);

#endif