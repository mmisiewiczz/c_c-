#include <stdio.h>

// Definiowanie unii przechowującej różne typy danych
union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    // Przypisanie i wyświetlenie wartości typu int
    data.i = 10;
    printf("Integer: %d\n", data.i);

    // Przypisanie i wyświetlenie wartości typu float
    data.f = 220.5;
    printf("Float: %f\n", data.f);

    // Przypisanie i wyświetlenie wartości typu char
    data.c = 'A';
    printf("Character: %c\n", data.c);

    return 0;
}
