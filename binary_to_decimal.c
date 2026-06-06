#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, rem;

    // Take binary input from the user
    printf("Enter a binary number (e.g., 1101): ");
    scanf("%lld", &binary);

    long long temp = binary; // Preserve original input for printing

    // Conversion loop
    while (temp > 0) {
        rem = temp % 10;          // Extract the last digit (0 or 1)
        decimal += rem * base;    // Add the digit's positional value to decimal
        base = base * 2;          // Update base to the next power of 2
        temp = temp / 10;         // Remove the last processed digit
    }

    // Display the final result
    printf("The binary number %lld in decimal is: %d\n", binary, decimal);

    return 0;
}

