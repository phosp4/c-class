# C Programming Guide

This is a short guide on some useful things you can do in C, which I prepared for my final open book exam.

## Pointers

These four lines do the same thing, dereferencing a pointer:

```c
*str = '\0';
*str = 0;
str[0] = '\0';
str[0] = 0;
```

## Dynamic Allocation

```c
char *str = (char*)malloc(MAX_STR_LEN + 1);

if (str == NULL) {
    printf("Allocation failed!\n");
    return EXIT_FAILURE;
}

memset(str, 0, MAX_STR_LEN + 1);

if (str != NULL) {
    free(str);
}
```

## Reading from Console

- `ret` is just a check, if it works it returns the address where the input is stored.
- It may happen that the text is not taken in `fflush`.

```c
char buffer[MAX_BUFFER_LEN];
bzero(buffer, MAX_BUFFER_LEN);

printf("Input string:");
fflush(stdout);

char *ret = fgets(buffer, MAX_BUFFER_LEN, stdin);

if (ret == NULL) {
    printf("Input error");
    return EXIT_FAILURE;
}

// Now I can read from the buffer
```

## Pointer to Pointer

```c
// Array of pointers
char *parray[100];

// All of these do the same thing
printf("output: %c \n", *(parray[0]));
printf("output: %c \n", (*parray)[0]);
printf("output: %c \n", parray[0][0]);
printf("output: %c \n", **parray);

// All of these also do the same thing
printf("output: %c \n", *(parray[0] + 1));
printf("output: %c \n", (*parray)[1]);
printf("output: %c \n", parray[0][1]);
printf("output: %c \n", *(*parray + 1));
```

You can also do this:

```c
char inputs[4][4] = {"asdf", "sdaf", "dsaf", "werw"};
```

## Structures

- Accessing elements:
  - If you have a pointer to a struct - use arrow notation.
  - If you have a struct - use dot notation.

- Initializing structure elements for simple data types:

```c
man.age = 25;
```

- For a pointer to a string (both ways):

```c
strcpy(man.name, "John");

strncpy(man.name, "John", sizeof(man.name) - 1);
man.name[sizeof(man.name) - 1] = '\0';
```

```c
// Derived data type
typedef struct {
    char street[20];
    uint16_t number;
    char city[50];
} address_t; // Convention is to use underscore t

struct Person {
    char name[10];
    char surname[20];
    uint8_t age;
    address_t addr; // Derived type - no need to write struct
};
```

You can also do this:

```c
struct Book book1 = {"C Programming", "John Doe", 300, 29.99};
```

## Unions and Enumerators

- Almost like a structure but either `name`, `age`, or `number` will be initialized.

```c
/*
    The size of this is 20 bytes
*/
union uni {
    char name[20];
    float age;
    short number;
};
```

```c
/*
    Enumerators are just numbers in order, we can also assign our own
*/
typedef enum {
    JAN = 5,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT = 100,
    NOV,
    DEC
} months_t;
```

```c
union uni u;
u.age = 20.0;

// This will overwrite age and write number
u.number = 50;
```

## Header Files

- Compilation: `gcc main.c mylib.c -o main` (must include `mylib.c`)

##### `mylib.h`

```c
#ifndef __MYLIB__
#define __MYLIB__

#include <stdio.h>
#include <stdint.h>

#define OPERATION_SUCCESS 1
#define OPERATION_FAILURE 0

uint8_t sum(int a, int b, int *out);
char* trim(char *s);

#endif
```

##### `mylib.c`

```c
#include "mylib.h"
// There should be no other includes or macros here

uint8_t sum(int a, int b, int *out)
{
    // ...
}

char* trim(char *s)
{
    // ...
}
```

##### `main.c`

```c
// Relative path from where this file is stored
#include "mylib.h"

int main(int argc, char *argv[])
{
    // ...
}
```

## Working with Files

- `fwrite` returns the number of successfully written elements.

##### Writing

```c
fwrite(/* what */, /* size of each element */, /* number of elements */, /* where */);
```

```c
FILE *fs = fopen(FILENAME, "w");

if (fs == NULL) {
    perror("Cannot write to file %s!" FILENAME);
    return EXIT_FAILURE;
}

size_t wnum = fwrite(buffer, 1, strlen(buffer), fs);
printf("%lu bytes written. \n", wnum);

fclose(fs);
```

##### Reading

```c
fread(/* what */, /* size of each element */, /* number of elements */, /* where */);
```

- One character at a time in this case:

```c
FILE *fs = fopen(FILENAME, "r");

if (fs == NULL) {
    perror("Cannot read from file!");
    return EXIT_FAILURE;
}

char one_char = 0;

while (fread(&one_char, 1, 1, fs)) { // Prints zero if we are at the end of the file
    // Remove some characters for example
    // ...
}

printf("\n");
printf("Is EOF? %d \n", feof(fs)); // feof checks end-of-file

fclose(fs);
```

- Before EOF: `Is EOF? 0`
- At EOF: `Is EOF? 1`

## Common Libraries Explained

- `<stdio.h>`: Console and file I/O. (`printf()`, `scanf()`, `fopen()`, `fgets()`)
- `<stdlib.h>`: Memory management, process control, conversions. (`malloc()`, `free()`, `atoi()`, `rand()`)
- `<unistd.h>`: System-level tasks (POSIX). (`fork()`, `exec()`, `sleep()`, `read()`)
- `<string.h>`: String and memory manipulation. (`strlen()`, `strcpy()`, `strcmp()`, `memset()`)
- `<stdint.h>`: Fixed-width integers. (`int32_t`, `uint8_t`, `int64_t`)

## Other Useful Resources

- [C Cheatsheet](https://courses.cs.washington.edu/courses/cse351/14sp/sections/1/Cheatsheet-c.pdf)
- [Format Specifiers in C](https://www.geeksforgeeks.org/format-specifiers-in-c/)
- [Quick Reference for C](https://quickref.me/c.html)
