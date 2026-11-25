#include <stdio.h>

float calculateDiscount(float amount, int *rate) {
    if (amount >= 5000) {
        *rate = 10;
        return amount * 0.10;
    } else if (amount >= 3000) {
        *rate = 5;
        return amount * 0.05;
    } else {
        *rate = 0;
        return 0.0;
    }
}
float calculateFinalAmount(float amount, float discount) {
    return amount - discount;
}
void displayReceipt(char name[], float amount) {
    int rate;
    float discount = calculateDiscount(amount, &rate);
    float finalAmount = calculateFinalAmount(amount, discount);

    printf("\n------ Receipt ------\n");
    printf("Customer Name  : %s\n", name);
    printf("Purchase Amount: Tk %.2f\n", amount);
    printf("Discount (%d%%)  : Tk %.2f\n", rate, discount);
    printf("Final Payable  : Tk %.2f\n", finalAmount);
}
int main() {
    char name[50];
    float amount;
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    do {
        printf("Enter purchase amount: ");
        scanf("%f", &amount);
        if (amount < 0) {
            printf("Invalid input. Purchase amount cannot be negative.\n");
        }
    }while (amount < 0);
    displayReceipt(name, amount);
}