#include <stdio.h>

int main() {
    int num, originalNum, rem, sum = 0;
    long fact;

    // Get input from the user
    printf("Enter an integer to check: ");
    scanf("%d", &num);

    // Copy the original number to preserve its value
    originalNum = num;

    // Handle edge case for 0 separately if needed, though 0! = 1
    if (num == 0) {
        sum = 1; 
    }

    // Process each digit of the number
    while (num > 0) {
        rem = num % 10; // Extract the last digit
        
        // Calculate the factorial of the extracted digit
        fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact *= i;
        }

        sum += fact;    // Add the factorial to the sum
        num /= 10;      // Remove the last digit from the number
    }

    // Verify if the sum matches the original number
    if (sum == originalNum) {
        printf("%d is a Strong Number.\n", originalNum);
    } else {
        printf("%d is NOT a Strong Number.\n", originalNum);
    }

    return 0;
}