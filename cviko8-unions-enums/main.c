#include <stdio.h>
#include <stdlib.h>

/*
    velkost tohto je 20 bajtov
    skoro ako struktura ale bud bude inicializovane name, age alebo number
*/
union uni {
    char name[20];
    float age;
    short number;
};

/*
    enumerator su len cisla v poradi, mozme si priradit aj vlastne
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

int main() {
    union uni u;
    u.age = 20.0;
    
    // toto prepise age a zapise number
    u.number = 50;
}