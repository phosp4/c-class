#ifndef __MYLIB__ // aby sa to iste nevlozilo dvakrat
#define __MYLIB__

#include <stdio.h>
#include <stdint.h>

#define OPERATION_SUCCESS 1
#define OPEERATION_FAILURE 0

uint8_t sum(int a, int b, int *out);
char* trim(char *s);

#endif