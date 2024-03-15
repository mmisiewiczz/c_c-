#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float final_grade;
} Student;

void sortStudents(Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].final_grade < students[j + 1].final_grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_students = 100;
    Student students[num_students];

    for (int i = 0; i < num_students; i++) {
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].final_grade = (float)(rand() % 101);
    }

    sortStudents(students, num_students);

    printf("Sorted list of students by final grades (descending):\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s - %.2f\n", students[i].name, students[i].final_grade);
    }

    return 0;
}
