#include <stdio.h>

int calculateTotal(int m1, int m2, int m3, int m4, int m5) {
    return m1 + m2 + m3 + m4 + m5;
}
float calculateAverage(int total) {
    return total / 5.0;
}
void calculateGrade(float avg, int m1, int m2, int m3, int m4, int m5, char **grade, float *gpa, char **result) {
    if (m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40) {
        *grade = "F";
        *gpa = 0.00;
        *result = "Fail";
    } else if (avg >= 80) {
        *grade = "A+";
        *gpa = 4.00;
        *result = "Pass";
    } else if (avg >= 70) {
        *grade = "A";
        *gpa = 3.50;
        *result = "Pass";
    } else if (avg >= 60) {
        *grade = "A-";
        *gpa = 3.00;
        *result = "Pass";
    } else if (avg >= 50) {
        *grade = "B";
        *gpa = 2.50;
        *result = "Pass";
    } else if (avg >= 40) {
        *grade = "C";
        *gpa = 2.00;
        *result = "Pass";
    } else {
        *grade = "F";
        *gpa = 0.00;
        *result = "Fail";
    }
}
void displayResult(char name[], int id, int m1, int m2, int m3, int m4, int m5) {
    int total = calculateTotal(m1, m2, m3, m4, m5);
    float avg = calculateAverage(total);
    char *grade, *result;
    float gpa;
    calculateGrade(avg, m1, m2, m3, m4, m5, &grade, &gpa, &result);

    printf("\n------ Student Result ------\n");
    printf("Name    : %s\n", name);
    printf("ID      : %d\n", id);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", avg);
    printf("Grade   : %s\n", grade);
    printf("GPA     : %.2f\n", gpa);
    printf("Result  : %s\n", result);
}
int main() {
    char name[50];
    int id, m1, m2, m3, m4, m5;
    printf("Enter student name: ");
    scanf(" %[^\n]", name);
    printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter marks of 5 subjects: ");
    scanf("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);

    if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100 || m4 < 0 || m4 > 100 || m5 < 0 || m5 > 100) {
        printf("Invalid marks. Each mark must be between 0 and 100.\n");
        return 0;
    }
    displayResult(name, id, m1, m2, m3, m4, m5);
}