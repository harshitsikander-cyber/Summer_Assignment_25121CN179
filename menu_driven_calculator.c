#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        // Step 1: Display the interactive menu
        printf("\n===============================\n");
        printf("     MENU-DRIVEN CALCULATOR     \n");
        printf("===============================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Terminate early if user chooses to exit
        if (choice == 5) {
            printf("\nExiting calculator program. Goodbye!\n");
            break;
        }

        // Validate choice before requesting operands
        if (choice < 1 || choice > 5) {
            printf("\nError: Invalid choice! Please select an option between 1 and 5.\n");
            continue; 
        }

        // Step 2: Request operands from user
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Step 3: Branch control evaluation using switch-case
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                // Safe runtime guard for division by zero
                if (num2 == 0.0) {
                    printf("\nError: Division by zero is mathematically undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default:
                printf("\nUnexpected system exception encountered.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}