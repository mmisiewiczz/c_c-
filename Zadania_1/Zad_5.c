#include <stdio.h>

int sum_of_multiples(int n) {
    if (n < 0) {
        return 0;
    }

    int total_sum = 0;
    for (int i = 3; i < n; i += 3) {
        total_sum += i;
    }
    for (int i = 5; i < n; i += 5) {
        if (i % 3 != 0) {
            total_sum += i;
        }
    }

    return total_sum;
}

int main() {
    // Testing the function for the number 10.
    printf("%d\n", sum_of_multiples(10));  // It should return 23

    return 0;
}
