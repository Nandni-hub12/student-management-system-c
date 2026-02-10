#include <stdio.h>

float balance = 1000;

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    balance += amount;
    printf("Deposit successful\n");
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > balance) {
        printf("Insufficient balance\n");
    } else {
        balance -= amount;
        printf("Withdrawal successful\n");
    }
}

void checkBalance() {
    printf("Current Balance: %.2f\n", balance);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Banking System ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: deposit(); break;
            case 2: withdraw(); break;
            case 3: checkBalance(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
