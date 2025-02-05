#include <stdio.h>

int main(int argc, char *argv[]) {

    for (int a = 10; a > 0; a--) {
        for (int b = 25; b > 0; b--) {
            printf("%d, %d - ahoj svet\n", a, b);
        }
    }
}