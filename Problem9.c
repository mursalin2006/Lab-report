#include <stdio.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    float fee;
};
int main() {
    int n, i;
    float totalFee = 0;
    printf("Enter number of patients: ");
    scanf("%d", &n);
    struct Patient p[n];

    for (i = 0; i < n; i++) {
        printf("Patient %d (ID name age disease fee): ", i + 1);
        scanf("%d %s %d %s %f", &p[i].id, p[i].name, &p[i].age, p[i].disease, &p[i].fee);
        totalFee += p[i].fee;
    }

    printf("\n%s \t%s \t%s \t%s %s\n", "ID", "Name", "Age", "Disease", "Fee");
    for (i = 0; i < n; i++) {
        printf("%d \t%s \t%d \t%s \t%2.2f\n", p[i].id, p[i].name, p[i].age, p[i].disease, p[i].fee);
    }
    printf("\nTotal consultation fees collected = Tk %.2f\n", totalFee);
}