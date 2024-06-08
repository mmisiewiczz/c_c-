#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funkcja do zamiany słów na cyfry
int word_to_digit(char *word) {
    if (strcmp(word, "jeden") == 0) return 1;
    if (strcmp(word, "dwa") == 0) return 2;
    if (strcmp(word, "trzy") == 0) return 3;
    if (strcmp(word, "cztery") == 0) return 4;
    if (strcmp(word, "pięć") == 0) return 5;
    if (strcmp(word, "sześć") == 0) return 6;
    if (strcmp(word, "siedem") == 0) return 7;
    if (strcmp(word, "osiem") == 0) return 8;
    if (strcmp(word, "dziewięć") == 0) return 9;
    return -1;
}

// Funkcja do znajdowania pierwszej cyfry w linii
int find_first_digit(char *line) {
    char word[20];
    int i = 0, j = 0;
    while (line[i] != '\0') {
        if (isdigit(line[i])) {
            return line[i] - '0';
        } else if (isalpha(line[i])) {
            word[j++] = line[i];
            if (!isalpha(line[i + 1])) {
                word[j] = '\0';
                int digit = word_to_digit(word);
                if (digit != -1) {
                    return digit;
                }
                j = 0;
            }
        }
        i++;
    }
    return -1; // Jeśli brak cyfry
}

// Funkcja do znajdowania ostatniej cyfry w linii
int find_last_digit(char *line) {
    char word[20];
    int j = 0;
    int last_digit = -1;
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            last_digit = line[i] - '0';
        } else if (isalpha(line[i])) {
            word[j++] = line[i];
            if (!isalpha(line[i + 1])) {
                word[j] = '\0';
                int digit = word_to_digit(word);
                if (digit != -1) {
                    last_digit = digit;
                }
                j = 0;
            }
        }
    }
    return last_digit;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[256];
    int total_sum = 0;
    while (fgets(line, sizeof(line), file)) {
        int first_digit = find_first_digit(line);
        int last_digit = find_last_digit(line);
        if (first_digit != -1 && last_digit != -1) {
            total_sum += first_digit * 10 + last_digit;
        }
    }
    fclose(file);

    printf("Suma wszystkich wartości energetycznych: %d\n", total_sum);
    return 0;
}
