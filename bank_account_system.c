#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Define account structure
typedef struct {
    int account_number;
    char holder_name[50];
    double balance;
} Account;

// Global array to store accounts and a counter
Account bank[MAX_ACCOUNTS];
int total_accounts = 0;

// Function declarations
void create_account();
void deposit();
void withdraw();
void check_balance();
int find_account(int acc_num);

int main() {
    int choice;

    while (1) {
        printf("\n=== BANK ACCOUNT MANAGEMENT SYSTEM ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Thank you for using our banking system!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

// 1. Function to create a new account
void create_account() {
    if (total_accounts >= MAX_ACCOUNTS) {
        printf("Error: Bank database is full. Cannot create more accounts.\n");
        return;
    }

    Account new_acc;
    printf("\n--- Create Account ---\n");
    printf("Enter a unique Account Number: ");
    scanf("%d", &new_acc.account_number);

    // Check if the account number already exists
    if (find_account(new_acc.account_number) != -1) {
        printf("Error: This account number already exists!\n");
        return;
    }

    printf("Enter Account Holder Name: ");
    getchar(); // Clear the newline character left in input buffer
    fgets(new_acc.holder_name, sizeof(new_acc.holder_name), stdin);
    new_acc.holder_name[strcspn(new_acc.holder_name, "\n")] = '\0'; // Remove newline

    printf("Enter Initial Deposit Amount: $");
    scanf("%lf", &new_acc.balance);

    if (new_acc.balance < 0) {
        printf("Error: Initial deposit cannot be negative.\n");
        return;
    }

    // Save to array
    bank[total_accounts] = new_acc;
    total_accounts++;
    printf("Account created successfully for %s!\n", new_acc.holder_name);
}

// Helper function to search for an account index by its number
int find_account(int acc_num) {
    for (int i = 0; i < total_accounts; i++) {
        if (bank[i].account_number == acc_num) {
            return i; // Return the array index
        }
    }
    return -1; // Account not found
}

// 2. Function to deposit money
void deposit() {
    int acc_num, index;
    double amount;

    printf("\n--- Deposit Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    index = find_account(acc_num);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Amount to Deposit: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be positive.\n");
        return;
    }

    bank[index].balance += amount;
    printf("Success! $%.2f deposited. New Balance: $%.2f\n", amount, bank[index].balance);
}

// 3. Function to withdraw money
void withdraw() {
    int acc_num, index;
    double amount;

    printf("\n--- Withdraw Money ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    index = find_account(acc_num);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter Amount to Withdraw: $");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive.\n");
        return;
    }

    if (amount > bank[index].balance) {
        printf("Error: Insufficient balance! Current Balance: $%.2f\n", bank[index].balance);
        return;
    }

    bank[index].balance -= amount;
    printf("Success! $%.2f withdrawn. Remaining Balance: $%.2f\n", amount, bank[index].balance);
}

// 4. Function to check account balance
void check_balance() {
    int acc_num, index;

    printf("\n--- Check Balance ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc_num);

    index = find_account(acc_num);
    if (index == -1) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", bank[index].account_number);
    printf("Holder Name   : %s\n", bank[index].holder_name);
    printf("Current Balance: $%.2f\n", bank[index].balance);
}