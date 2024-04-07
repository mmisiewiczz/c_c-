#include <stdio.h>

// Funkcja do obliczania współczynnika dwumianowego n po k
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// Funkcja do wyświetlania trójkąta Pascala
void displayPascalTriangle(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    int height;
    printf("Give the height of Pascal's triangle: ");
    scanf("%d", &height);
    
    printf("Pascal's triangle with height %d:\n", height);
    displayPascalTriangle(height);

    return 0;
}
