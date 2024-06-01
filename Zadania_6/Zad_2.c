#include <stdio.h>

// Funkcja dodawania
int add(int a, int b) {
    return a + b;
}

// Funkcja mnożenia
int multiply(int a, int b) {
    return a * b;
}

// Funkcja odejmowania
int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Deklaracja wskaźnika do funkcji
    int (*operation)(int, int);
    int choice, a, b;

    // Wyświetlanie menu wyboru operacji
    printf("Choose an operation:\n1. Add\n2. Multiply\n3. Subtract\n");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Wybór odpowiedniej funkcji na podstawie wejścia użytkownika
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = multiply;
            break;
        case 3:
            operation = subtract;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    // Wywołanie wybranej funkcji i wyświetlenie wyniku
    int result = operation(a, b);
    printf("Result: %d\n", result);

    return 0;
}
