#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define MAX_PERSONS 100                 // Size of persons array
#define MAX_BUF_LEN 256                 // Max size of buffer for common use

#define NAME_LENGTH 30                  // Max size of name - person_t structure item
#define SURNAME_LENGTH 30               // Max size of surname - person_t structure item
#define MAX_AGE 150                     // Highest acceptable age - person_t structure item
#define STREET_LENGTH 30                // Max size of street - address_t structure item
#define CITY_LENGTH 30                  // Max size of city - address_t structure item
#define MAX_HNUMBER 65535               // Highest allowable street number - address_t structure item

#define OPERATION_SUCCESS 1             // Used as return value of successful operation
#define OPERATION_FAIL    0             // Used as return value of unsuccessful operation

typedef struct {
    char street[STREET_LENGTH];
    uint16_t number;
    char city[CITY_LENGTH];
} address_t;

typedef struct {
    char name[NAME_LENGTH];
    char surname[SURNAME_LENGTH];
    uint16_t age;
    address_t adr;
    uint8_t valid;
} person_t;

/*
    function rtrim - removes white characters from end of string
*/
void rtrim(char *str)
{

    if (str == NULL) return;

    size_t len = strlen(str);

    // find end of string after which are just white chars
    uint16_t last_char = 0;

    for (uint16_t i = 0; i < len; i++) {
        if (str[i] > 32) {
            last_char = i;
        }
    }
    
    str[last_char+1] = '\0';
}

void clear_struct_item(person_t *p) {
    if (p == NULL) return;
    memset(p->adr.city, 0, CITY_LENGTH);
    memset(p->adr.number, 0, MAX_HNUMBER);
    memset(p->name, 0, NAME_LENGTH);
    memset(p->surname, 0, SURNAME_LENGTH);
    p->age = 0;
    p->valid = 0;
    p->adr.number = 0;
}

int main (int argc, char *argv[]) {    
    char str[] = "     ";
    rtrim(str);
    printf("out: [%s]\n", str);
}