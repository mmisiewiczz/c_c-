#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

// Funkcja konwertująca słowa na cyfry
char convert_word_to_digit(const char *word) {
    if (strcmp(word, "one") == 0) return '1';
    if (strcmp(word, "two") == 0) return '2';
    if (strcmp(word, "three") == 0) return '3';
    if (strcmp(word, "four") == 0) return '4';
    if (strcmp(word, "five") == 0) return '5';
    if (strcmp(word, "six") == 0) return '6';
    if (strcmp(word, "seven") == 0) return '7';
    if (strcmp(word, "eight") == 0) return '8';
    if (strcmp(word, "nine") == 0) return '9';
    return 0;
}

// Funkcja wyciągająca wartość energetyczną z linii tekstu
int extract_energy_value(const char *line) {
    char first_digit = 0, last_digit = 0;
    int len = strlen(line);
    char word[10];
    int j = 0;
    int found_first = 0;  // Flaga, aby oznaczyć znalezienie pierwszej cyfry

    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])) {
            if (!found_first) {
                first_digit = line[i];
                found_first = 1;
            }
            last_digit = line[i];
        } else if (isalpha(line[i])) {
            word[j++] = line[i];
            word[j] = '\0';
            if (j >= 3) {
                char digit = convert_word_to_digit(word);
                if (digit) {
                    if (!found_first) {
                        first_digit = digit;
                        found_first = 1;
                    }
                    last_digit = digit;
                    j = 0;
                }
            }
        } else {
            j = 0;
        }
    }
    if (first_digit && last_digit) {
        char combined[3] = {first_digit, last_digit, '\0'};
        return atoi(combined);
    }
    return 0;
}

// Funkcja obliczająca sumę wartości energetycznych i zwracająca poszczególne wartości dla każdej linii
int calculate_total_energy(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Nie można otworzyć pliku %s\n", file_path);
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    int total_energy = 0;
    while (fgets(line, sizeof(line), file)) {
        int energy_value = extract_energy_value(line);
        printf("Linia: %sWartość energetyczna: %d\n", line, energy_value);
        total_energy += energy_value;
    }
    fclose(file);
    return total_energy;
}

int main() {
    const char *file_path = "input.txt";
    int total_energy = calculate_total_energy(file_path);
    if (total_energy >= 0) {
        printf("Całkowita wartość energetyczna: %d\n", total_energy);
    }
    return 0;
}
