#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate permutations
void permute(int *array, int start, int end) {
    // Base case: if start index reaches the end, print the permutation
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        // Recursive case: generate permutations by swapping elements
        for (int i = start; i <= end; i++) {
            swap(&array[start], &array[i]); // Swap elements at index start and i
            permute(array, start + 1, end); // Recur for the remaining elements
            swap(&array[start], &array[i]); // Restore the array to its original configuration
        }
    }
}

int main() {
    int array[] = {1, 2, 3, 4};
    int n = sizeof(array) / sizeof(array[0]);

    // Generate permutations and display them
    permute(array, 0, n - 1);

    return 0;
}
