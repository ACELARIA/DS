#include <stdio.h>
#include <string.h>

struct BankMgmt {
    char AccNumber[20];
    char CustName[50];
    float AvlBalance;
    char AccType[20];
};

int main() {
    struct BankMgmt account;
    int choice;
    float amount;
    
    strcpy(account.AccNumber, "SB100155");
    strcpy(account.CustName, "Venkat Krishna");
    account.AvlBalance = 4500.00;
    strcpy(account.AccType, "Saving");

    do {
        printf("\nBank Management System\n");
        printf("1. Withdrawal\n");
        printf("2. Deposit\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > account.AvlBalance) {
                    printf("Insufficient balance.\n");
                } else {
                    account.AvlBalance -= amount;
                    printf("Withdrawal successful.\n");
                }
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                account.AvlBalance += amount;
                printf("Deposit successful.\n");
                break;
            case 3:
                printf("\nAccount Details:\n");
                printf("Account Number: %s\n", account.AccNumber);
                printf("Customer Name: %s\n", account.CustName);
                printf("Account Type: %s\n", account.AccType);
                printf("Available Balance: %.2f\n", account.AvlBalance);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } 
    while (choice!=4);
    return 0;
}