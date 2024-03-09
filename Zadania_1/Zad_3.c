#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++) {
        int result = 1;
        for (int j = 1; j <= array[i]; j++) {
            result *= j;
        }
        printf("Silnia dla liczby %d: %d\n", array[i], result);
    }
    
    return 0;
}
