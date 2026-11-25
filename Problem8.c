#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basic;
    float houseRent;
    float medical;
    float gross;
};
int main() {
    int n, i;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee e[n];

    for (i = 0; i < n; i++) {
        printf("Employee %d (ID name basic house-rent medical): ", i + 1);
        scanf("%d %s %f %f %f", &e[i].id, e[i].name, &e[i].basic, &e[i].houseRent, &e[i].medical);
        e[i].gross = e[i].basic + e[i].houseRent + e[i].medical;
    }

    printf("\n%s \t%s \t%s \t\t%s \t%s \t%s\n", "ID", "Name", "Basic", "HouseRent", "Medical", "Gross");
    for (i = 0; i < n; i++) {
        printf("%d \t%s \t%.2f \t%.2f \t\t%.2f \t\t%.2f\n", e[i].id, e[i].name, e[i].basic, e[i].houseRent, e[i].medical, e[i].gross);
    }
}