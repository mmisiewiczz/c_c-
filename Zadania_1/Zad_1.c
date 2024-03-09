#include <stdio.h>

int main() {
    char name[100]; // Deklaracja tablicy na imię o maksymalnej długości 100 znaków

    printf("What's your name?: ");
    scanf("%s", name); // Wczytanie imienia ze standardowego wejścia

    printf("Hello, %s!\n", name); // Wyświetlenie powitania z imieniem użytkownika

    return 0;
}