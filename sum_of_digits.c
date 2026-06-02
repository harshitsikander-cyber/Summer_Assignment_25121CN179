
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, remainder, sum = 0;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Convert negative numbers to positive to handle all integers correctly
    int temp = abs(number);

    // Loop to extract and sum up each digit
    while (temp > 0) {
        remainder = temp % 10;  // Extract the last digit
        sum += remainder;       // Add the digit to sum
        temp = temp / 10;       // Remove the last digit from the number
    }

    // Display the final result
    printf("The sum of the digits of %d is: %d\n", number, sum);

    return 0;
}