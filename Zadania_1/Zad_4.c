#include <stdio.h>

int main() {
    for (int i = 1; i <= 200; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            printf("%-6s", "FooBar");
        } else if (i % 5 == 0) {
            printf("%-6s", "Foo");
        } else if (i % 7 == 0) {
            printf("%-6s", "Bar");
        } else {
            printf("%-6d", i);
        }
        if (i % 10 == 0) {
            printf("\n");
        }        
    }
    return 0;
}
