// File: calculate_energy.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mapa słów na cyfry w języku angielskim
const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char digits_map[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Funkcja zamieniająca słowo na cyfrę
char word_to_digit(const char *word) {
    for (int i = 0; i < 9; i++) {
        if (strcmp(word, words[i]) == 0) {
            return digits_map[i];
        }
    }
    return '\0';
}

// Funkcja wyciągająca cyfry z linii, uwzględniając słowa
void extract_digits_with_words(const char *line, char *digits, int *count) {
    int len = strlen(line);
    char word[256];  // Zwiększony rozmiar tablicy
    int word_index = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])) {
            digits[(*count)++] = line[i];
        } else if (isalpha(line[i])) {
            word[word_index++] = line[i];
        } else {
            if (word_index > 0) {
                word[word_index] = '\0';
                char digit = word_to_digit(word);
                if (digit) {
                    digits[(*count)++] = digit;
                }
                word_index = 0;
            }
        }
    }

    // Sprawdzenie ostatniego słowa
    if (word_index > 0) {
        word[word_index] = '\0';
        char digit = word_to_digit(word);
        if (digit) {
            digits[(*count)++] = digit;
        }
    }
}

// Funkcja obliczająca wartość energetyczną linii z uwzględnieniem słów
int calculate_energy_value_with_words(const char *line) {
    char digits[256];
    int count = 0;
    extract_digits_with_words(line, digits, &count);

    if (count < 2) {
        return 0;
    }

    char buffer[3];
    buffer[0] = digits[0];
    buffer[1] = digits[count - 1];
    buffer[2] = '\0';

    return atoi(buffer);
}

int main() {
    // Otwórz plik input.txt do odczytu
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return 1;
    }

    char line[256];
    int total_energy = 0;

    // Przetwarzaj każdą linię z pliku
    while (fgets(line, sizeof(line), file)) {
        total_energy += calculate_energy_value_with_words(line);
    }

    // Zamknij plik
    fclose(file);

    // Wypisz całkowitą wartość energetyczną
    printf("Total energy value: %d\n", total_energy);
    return 0;
}
