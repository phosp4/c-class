#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define MAX_PERSONS 100
#define MAX_INPUT_LEN 30

// odvodeny udajovy typ
typedef struct {
    char street[MAX_INPUT_LEN];
    uint16_t number;
    char city[MAX_INPUT_LEN];
} address_t;

struct Person {
    char name[MAX_INPUT_LEN];
    char surname[MAX_INPUT_LEN];
    uint8_t age;
    address_t addr;
};

void print_person(struct Person *p)
{
    // k jednotlivym zlozkam pristupujem cez ukazovatel - sipkova konvencia
    printf("User:     %s %s with age of %d\n", p->name, p->surname, p->age);

    // tu je druha uz bodka, lebo tam uz pracujem so strukturou, nie len ukazovatelom
    printf("Address:  %s %d, %s \n", p->addr.street, p->addr.number, p->addr.city);
}

int add_person(struct Person *p) {
        struct Person new;

        char buffer[MAX_INPUT_LEN];
        bzero(buffer, MAX_INPUT_LEN);

        char inputs[4][4] = {"asdf", "sdaf", "dsaf", "werw"};

        for (u_int8_t i = 0; i < sizeof(inputs); i++) {
            printf("something: %s \n", inputs[i]);
        }

        //printf("Add name: ");

        char *ret = fgets(buffer, sizeof(buffer), stdin);
        if (ret == NULL) {
            printf("Input error");
            return EXIT_FAILURE;
        }

        strcpy(new.name, buffer);
    }

int main(int argc, char* argv[]) {

    struct Person p[MAX_PERSONS];

    char buffer[10];
    bzero(buffer, 10);

    while (1) {
    //for (int i = 0; i<3; i++) {
        printf("1. Add person \n");
        printf("2. Remove person \n");
        printf("3. List persons \n");
        printf("4. Exit application \n");
        printf("------------------------------ \n");
        printf("Your choice: \n");
        fflush(stdout);

        char *ret = fgets(buffer, sizeof(buffer), stdin);
        if (ret == NULL) {
            printf("Input error");
            return EXIT_FAILURE;
        }

        // Ensure only single-character inputs are valid for switch
        if (strlen(buffer) != 1) {
            printf("Invalid choice. Please enter a single digit.\n");
            continue;
        }
        
        switch (buffer[0]) {
            case '1':
                add_person(p);
                break;
            case '2':
                remove_person(p);
                break;
            case '3':
                list_persons(p);
                break;
            case '4':
                printf("Exitting the application... \n");
                return EXIT_SUCCESS;
            default:
                continue;
        }
    }

    printf("buffer: %s \n", buffer);

    /////// dokoncit doma (zaverecne zadanie bude takto nejako vyzerat)

    return EXIT_SUCCESS;
}