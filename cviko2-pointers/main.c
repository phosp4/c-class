#include <stdio.h>

void pripocitaj(int *prm, int cislo) {
    *prm += 10;
    // nemusime nic vracat, to je dolezite
}

int main() {
    
    int a = 10;
    int b = 15;

    // vytvor pointer na a
    int *pa = &a;

    // posli ho cez funkciu ktora ho upravy
    pripocitaj(pa, 10);

    printf("hodnota a je %d, to je rovne %d, a hodnota b je %d \n", a, *pa, b);
    printf("adresa premennej a v pamati je %p \n", pa);

    int *px = NULL;

    printf("adresa premennej px v pamati je %p \n", px);

    // polia
    char pole[12];
    pole[0] = 'a';
    pole[1] = 'h';
    pole[2] = 'o';
    pole[3] = 'j';

    printf("hodnota na pozicii 1 je %c \n", pole[1]);
    printf("hodnota na pozicii 1 je %c \n", *(pole + 1));

    void *asdf;
}