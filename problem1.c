#include <stdio.h>

int calculateBill(int units) {
    int billAmount;
    do{
        if (units < 0) {
            printf("Invalid input. Please enter a non-negative value for units consumed: ");
            scanf("%d", &units);
        }}while (units < 0);
        if (units <= 100) {
        billAmount = units * 5; // Rate for first 100 units
        } else if (units <= 200) {
        billAmount = (100 * 5) + ((units - 100) * 6); // Rate for next 100 units
        } else {
        billAmount = (100 * 5) + (100 * 6) + ((units - 200) * 8); // Rate for units above 200
        }
        return billAmount;
}
int calculateVAT(int billAmount) {
    return billAmount * 0.05; // 5% VAT
}
void displayBill(int customerID, char name[], int units) {
    int billAmount = calculateBill(units);
    int vatAmount = calculateVAT(billAmount);
    float totalAmount = billAmount + vatAmount;

    printf("\n------Electricity Bill------");
    printf("\nCustomer ID: %d\n", customerID);
    printf("Customer Name: %s\n", name);
    printf("Units Consumed: %d\n", units);
    printf("Electricity Charge: %d\n", billAmount);
    printf("VAT (5%%): %d\n", vatAmount);
    printf("Final Bill: %.2f\n", totalAmount);
}
int main() {
    int units, customerID;
    char name[50];
    printf("Enter Customer ID: ");
    scanf("%d", &customerID);
    printf("Enter Customer Name: ");
    scanf("%s", name);
    printf("Enter Units Consumed: ");
    scanf("%d", &units);
    calculateBill(units);
    calculateVAT(calculateBill(units));
    displayBill(customerID, name, units);
}
