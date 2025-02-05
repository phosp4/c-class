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
    char *last_char = str+strlen(str);
    while (last_char >= str) {
        if (*last_char < 32) *last_char = 0;
        last_char--;
    }
}

/*
    function clear_struct_item - clears content of person_t and address_t structures items
*/
void clear_struct_item(person_t *p)
{
    if (p == NULL) return;
    memset(p->name, 0, NAME_LENGTH);
    memset(p->surname, 0, SURNAME_LENGTH);
    memset(p->adr.street, 0, STREET_LENGTH);
    memset(p->adr.city, 0, CITY_LENGTH);
    p->age = 0;
    p->valid = 0;
    p->adr.number = 0;
}

/*
    function move_struct_item - moves content of item from one to another location
*/
void move_struct_item(person_t *dst, person_t *src)
{
    strcpy(dst->name, src->name);
    strcpy(dst->surname, src->surname);
    strcpy(dst->adr.street, src->adr.street);
    strcpy(dst->adr.city, src->adr.city);
    dst->age = src->age;
    dst->adr.number = src->adr.number;
    dst->valid = 1;
    clear_struct_item(src);
}

/*
    function init_persons - initializes structures items to default values
*/
void init_persons(person_t p[])
{
    for (uint16_t i=0; i<MAX_PERSONS; i++) {
        clear_struct_item(&p[i]);
    }
}

/*
    function print_persons - lists (prints) all persons alongsides with their addresses
*/
void print_persons(person_t p[])
{
    uint16_t total_persons = 0;
    for (uint16_t i=0; i<MAX_PERSONS; i++) {
        if (p[i].valid) {
            printf("[%03u] User: %s %s [age: %u]\n", i, p[i].name, p[i].surname, p[i].age);
            printf("Address:    %s %u, %s\n", p[i].adr.street, p[i].adr.number, p[i].adr.city);
            total_persons++;
        }
    }
    if (total_persons == 0) {
        printf("List of persons is empty.\n\n");
    } else {
        printf("Listed %u person(s).\n\n", total_persons);
    }
}

/*
    function read_from_input - reads input from stdin and stores it in dest variable
*/
uint8_t read_from_input(const char *prompt, char *dest, uint16_t dest_size)
{
    printf("%s: ", prompt);
    fflush(stdout);
    char buffer[dest_size];
    memset(buffer, 0, dest_size);
    fgets(buffer, dest_size, stdin);
    if (buffer == NULL) {
        return OPERATION_FAIL;
    }
    strcpy(dest, buffer);
    rtrim(dest);
    if (strlen(dest) == 0) {
        return OPERATION_FAIL;
    }
    return OPERATION_SUCCESS;
}

/*
    function read_string_from input - reads string from stdin
*/
uint8_t read_string_from_input(const char *prompt, char *dest, uint16_t dest_size)
{
    return read_from_input(prompt, dest, dest_size);
}

/*
    function read_number_from input - reads unsigned integer from stdin
*/
uint8_t read_number_from_input(const char *prompt, uint16_t *dest)
{
    char buffer[MAX_BUF_LEN];
    memset(buffer, 0, MAX_BUF_LEN);
    if (read_from_input(prompt, buffer, MAX_BUF_LEN) == OPERATION_SUCCESS) {
        *dest = atoi(buffer);
        return OPERATION_SUCCESS;
    }
    return OPERATION_FAIL;
}

/*
    function add_person - adds new item into person_t structure
*/
void add_person(person_t p[])
{
    uint16_t free_position = 0;
    for (; free_position<MAX_PERSONS; free_position++) {
        if (!p[free_position].valid) {
            break;
        }
    }
    if (read_string_from_input("Insert person's name", p[free_position].name, NAME_LENGTH) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    if (read_string_from_input("Insert person's surname", p[free_position].surname, SURNAME_LENGTH) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    if (read_number_from_input("Insert person's age", &(p[free_position].age)) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    if (read_string_from_input("Insert person's address street", p[free_position].adr.street, STREET_LENGTH) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    if (read_number_from_input("Insert person's address street number", &(p[free_position].adr.number)) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    if (read_string_from_input("Insert person's address city", p[free_position].adr.city, CITY_LENGTH) == OPERATION_FAIL) {
        printf("Insertion failed!\n\n");
        return;
    }
    p[free_position].valid = 1;
    printf("Person successfully added.\n\n");
}

/*
    function remove_person - removes existing item from person_t structure
*/
void remove_person(person_t p[])
{
    uint16_t person_id = 0;
    if (read_number_from_input("Provide ID of person to be removed", &person_id) == OPERATION_SUCCESS) {
        if (p[person_id].valid) {
            clear_struct_item(&p[person_id]);
            printf("Person successfully removed. \n\n");
            return;
        }
    }
    printf("Invalid operation!\n\n");
}

/*
    function reorder_persons_list_1 - rearranges the items in the person_t structure by moving the items to the beginning of the array
*/
void reorder_persons_list_1(person_t p[])
{
    int32_t last_high_position = (MAX_PERSONS-1);
    int32_t last_low_position  = 0;
    uint16_t items_moves       = 0;
    for (int32_t i=(MAX_PERSONS-1); i>=0; i--) {
        if (p[i].valid) {
            last_high_position = i;
            for (int32_t x=last_low_position; x<MAX_PERSONS; x++) {
                if (p[x].valid == 0) {
                    last_low_position = x;
                    if (last_high_position < last_low_position) break;
                    printf("Moving from %d to %d \n", last_high_position, last_low_position);
                    move_struct_item(&p[x], &p[i]);
                    items_moves++;
                    break;
                }
            }
        }
    }
    printf("Reordering finished with %u moves. \n\n", items_moves);
}

/*
    function reorder_persons_list_2 - moves items with higher indices in the person_t structure to lower indices by copying the whole memory of items
*/
void reorder_persons_list_2(person_t p[])
{
    int32_t low_empty_position  = 0;
    int32_t low_full_position   = 0;
    uint16_t items_moves        = 0;
    uint8_t moving_operation    = 0;
    uint8_t performed_operation = 0;
    do {
        performed_operation = 0;
        for (int32_t i=low_empty_position; i<MAX_PERSONS; i++) {
            if ((p[i].valid == 0) && (moving_operation == 0)) {
                moving_operation   = 1;
                low_empty_position = i;
                if (low_full_position > i) {
                    i = low_full_position;
                }
                continue;
            }
            if ((p[i].valid) && (moving_operation == 1)) {
                memcpy((void*)&p[low_empty_position], (void*)&p[i], sizeof(person_t));
                printf("Moving from %d to %d \n", i, low_empty_position);
                clear_struct_item(&p[i]);
                low_empty_position++;
                items_moves++;
                if (i < (MAX_PERSONS-1)) {
                    low_full_position   = i;
                    performed_operation = 1;
                }
                break;
            }
        }
    } while (performed_operation);
    printf("Reordering finished with %u moves. \n\n", items_moves);
}

/*
    function main - program starting point
*/
int main(int argc, char *argv[])
{
    person_t p[MAX_PERSONS];
    init_persons(p);

    while (1) {
        printf("1. Add person\n");
        printf("2. Remove person\n");
        printf("4. Reorder list of persons (type 1)\n");
        printf("5. Reorder list of persons (type 2)\n");
        printf("9. List persons\n");
        printf("0. Exit application\n");
        printf("----------------------------\n");
        // input[3] array used only for choosing menu option: [0] -> option, [1] -> Enter, [2] -> null character
        char input[3] = {0};
        if (read_from_input("Choose your option", input, 3) == OPERATION_SUCCESS) {
            switch (input[0]) {
                case '1':
                    add_person(p);
                    break;
                case '2':
                    remove_person(p);
                    break;
                case '4':
                    reorder_persons_list_1(p);
                    break;
                case '5':
                    reorder_persons_list_2(p);
                    break;
                case '9':
                    print_persons(p);
                    break;
                case '0':
                    printf("Quit!\n");
                    return EXIT_SUCCESS;
                default:
                    printf("Unknown choice! Try again.\n");
            }
        }
    }

    return EXIT_SUCCESS;
}

// End of file