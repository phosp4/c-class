#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define MAX_PERSONS 100

// odvodeny udajovy typ
typedef struct {
    char street[20];
    uint16_t number;
    char city[50];
} address_t; // konvencia je davat podciarnik t

struct Person {
    char name[10];
    char surname[20];
    uint8_t age;
    address_t addr; // odvodeny typ - netreba pisat struct
};
// vkladame ukazovatel na strukturu, mozme aj strukturu samotnu, len potom bodkova konvencia
// zaroven to je ovela ekonomickejsie davat na vstup ukazovatel, inak sa kopiruje vsetko
void print_person(struct Person *p)
{
    // k jednotlivym zlozkam pristupujem cez ukazovatel - sipkova konvencia
    printf("User:     %s %s with age of %d\n", p->name, p->surname, p->age);

    // tu je druha uz bodka, lebo tam uz pracujem so strukturou, nie len ukazovatelom
    printf("Address:  %s %d, %s \n", p->addr.street, p->addr.number, p->addr.city);
}

int main(int argc, char* argv[]) {

    struct Person man;

    // k zlozke pristupujem cez strukturu - bodkova komvencia
    man.age = 25;

    // toto nebude fungovat, memory leak, tak by sme to robili keby bol man pointer
    //man.name = "John";
    strcpy(man.name, "John"); // inak nebezpecna funkcia
    strcpy(man.surname, "Doe");
    strcpy(man.addr.street, "New street");
    man.addr.number = 50;
    strcpy(man.addr.city, "New York");

    print_person(&man);

    struct Person p[MAX_PERSONS];

    return EXIT_SUCCESS;
}