#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 2

int main() {
    float grades[NUM_SUBJECTS][NUM_STUDENTS];
    float averages[NUM_SUBJECTS] = {0}; // Initialization of the array of average grades for each subject
    
    // Reading grades for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the grade for mathematics for student %d: ", i + 1);
        scanf("%f", &grades[0][i]);
        
        printf("Enter the grade for physics for student %d: ", i + 1);
        scanf("%f", &grades[1][i]);
    }
    
    // Calculating average grades for each subject
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        for (int j = 0; j < NUM_STUDENTS; j++) {
            averages[i] += grades[i][j];
        }
        averages[i] /= NUM_STUDENTS;
    }
    
    // Displaying the results
    printf("\nAverage grade for mathematics: %.2f\n", averages[0]);
    printf("Average grade for physics: %.2f\n", averages[1]);
    
    return 0;
}
