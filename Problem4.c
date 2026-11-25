#include <stdio.h>

int validateWithdrawal(int amount) {
    if (amount > 0 && amount % 500 == 0) {
        return 1;
    }
    return 0;
}
int checkBalance(int balance, int amount) {
    if (balance >= amount) {
        return 1;
    }
    return 0;
}
int withdrawMoney(int balance, int amount) {
    return balance - amount;
}
void displayTransaction(int balance, int amount) {
    if (!validateWithdrawal(amount)) {
        printf("\nTransaction Status : Failed (Invalid amount,must be positive and multiple of Tk 500)\n");
        printf("Amount Withdrawn   : Tk 0\n");
        printf("Remaining Balance  : Tk %d\n", balance);
    } else if (!checkBalance(balance, amount)) {
        printf("\nTransaction Status : Failed (Insufficient balance)\n");
        printf("Amount Withdrawn   : Tk 0\n");
        printf("Remaining Balance  : Tk %d\n", balance);
    } else {
        int rem = withdrawMoney(balance, amount);
        printf("\nTransaction Status : Successful\n");
        printf("Amount Withdrawn   : Tk %d\n", amount);
        printf("Remaining Balance  : Tk %d\n", rem);
    }
}
int main() {
    int balance, amount;
    printf("Enter account balance: ");
    scanf("%d", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);
    displayTransaction(balance, amount);
}