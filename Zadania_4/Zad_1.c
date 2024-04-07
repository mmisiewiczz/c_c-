#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long factorial(int n) {
    // Base case: if n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: return n multiplied by factorial of (n-1)
    return n * factorial(n - 1);
}

int main() {
    int num;
    unsigned long long fact;

    // Input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate factorial
    fact = factorial(num);

    // Display the result
    printf("Factorial of %d = %llu\n", num, fact);

    return 0;
}
