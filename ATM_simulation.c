#include <stdio.h>
#include <stdlib.h>

// Function declarations
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main() {
    int pin = 1234;          // Default secret PIN
    int enteredPin;
    int attempts = 0;
    int choice;
    double balance = 5000.0; // Initial account balance
    int isRunning = 1;

    printf("=========================================\n");
    printf("       WELCOME TO THE ATM SIMULATOR      \n");
    printf("=========================================\n");

    // PIN Authentication Loop (Maximum 3 attempts)
    while (attempts < 3) {
        printf("\nPlease enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input type. Please enter numbers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            attempts++;
            continue;
        }

        if (enteredPin == pin) {
            printf("\nVerification Successful!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", 3 - attempts);
        }
    }

    // Terminate program if PIN is failed 3 times
    if (attempts == 3) {
        printf("\nToo many incorrect attempts. Your card has been blocked.\n");
        printf("Please contact your bank branch for assistance.\n");
        return 0;
    }

    // Main Transaction Menu
    while (isRunning) {
        printf("\n-----------------------------------------\n");
        printf("                ATM MENU                 \n");
        printf("-----------------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please select from the menu options.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using our ATM services. Goodbye!\n");
                isRunning = 0;
                break;
            default:
                printf("Invalid selection. Please choose a number between 1 and 4.\n");
        }
    }

    return 0;
}

// Function to print the current account balance
void checkBalance(double balance) {
    printf("\n>>> Your current balance is: $%.2f\n", balance);
}

// Function to handle safe account deposits
double depositMoney(double balance) {
    double depositAmount;
    printf("\nEnter the amount to deposit: $");
    
    if (scanf("%u%lf", &depositAmount) != 1 || depositAmount <= 0) {
        printf("Transaction Failed: Invalid deposit amount.\n");
        while (getchar() != '\n'); // Clear input buffer
        return balance;
    }

    balance += depositAmount;
    printf("Successfully deposited $%.2f\n", depositAmount);
    printf(">>> New Balance: $%.2f\n", balance);
    return balance;
}

// Function to handle cash withdrawals with balance checks
double withdrawMoney(double balance) {
    double withdrawAmount;
    printf("\nEnter the amount to withdraw: $");

    if (scanf("%lf", &withdrawAmount) != 1 || withdrawAmount <= 0) {
        printf("Transaction Failed: Invalid withdrawal amount.\n");
        while (getchar() != '\n'); // Clear input buffer
        return balance;
    }

    // Validation: Check if sufficient funds exist
    if (withdrawAmount > balance) {
        printf("Transaction Failed: Insufficient funds available.\n");
    } else {
        balance -= withdrawAmount;
        printf("Successfully withdrew $%.2f\n", withdrawAmount);
        printf(">>> Remaining Balance: $%.2f\n", balance);
    }
    return balance;
}