#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to allocate memory for a 2D matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

// Function to fill the matrix with random numbers
void fillMatrix(int** matrix, int rows, int cols) {
    srand(time(NULL)); // Initialize the random number generator

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Generate a random number between 0-99
        }
    }
}

// Function to display the contents of the matrix
void displayMatrix(int** matrix, int rows, int cols) {
    printf("Matrix contents:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    int** matrix = allocateMatrix(rows, cols);

    // Fill the matrix with random numbers
    fillMatrix(matrix, rows, cols);

    // Display the contents of the matrix
    displayMatrix(matrix, rows, cols);

    // Free the allocated memory
    freeMatrix(matrix, rows);

    return 0;
}
