#include <stdio.h>

void dubbleValue (float *prt) {
    *prt *= 2;
}

void main (){
    float num = 20;
    printf("Value of variable num before making changes: %.2f\n", num);
    dubbleValue(&num);
    printf("Value after dubbled: %.2f\n", num);
}