#include <stdio.h>

    int main() {
        int num = 10;
        int* ptr = &num;
        *ptr = 20;
        printf("Value directly from variable %d\n", num);
        printf("Value from pointer %d", *ptr);

        return 0;
    }
