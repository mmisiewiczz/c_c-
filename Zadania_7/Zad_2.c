#include <stdio.h>
#include <stdlib.h>

// Funkcja do obliczania tablicy sum prefixów
void calculate_prefix_sums(int* input, int* output, int size) {
    output[0] = input[0];
    for (int i = 1; i < size; i++) {
        output[i] = output[i - 1] + input[i];
    }
}

int main() {
    FILE *file = fopen("input_2.txt", "r");
    if (!file) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    int n;
    // Pobieranie liczby elementów tablicy
    fscanf(file, "%d", &n);

    // Alokacja pamięci dla tablicy wejściowej i wyjściowej
    int* input = (int*)malloc(n * sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));

    if (input == NULL || output == NULL) {
        printf("Błąd alokacji pamięci\n");
        fclose(file);
        return 1;
    }

    // Pobieranie elementów tablicy wejściowej
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &input[i]);
    }
    fclose(file);

    // Obliczanie tablicy sum prefixów
    calculate_prefix_sums(input, output, n);

    // Wyświetlanie tablicy wyjściowej
    printf("Tablica sum prefixów: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Zwolnienie pamięci
    free(input);
    free(output);

    return 0;
}
