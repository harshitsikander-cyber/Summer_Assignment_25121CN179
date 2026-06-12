#include <stdio.h>

// Function declaration (Prototype)
unsigned long long findFactorial(int n);

int main() {
    int number;
    unsigned long long result;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check for negative input since factorial is not defined for negative numbers
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        result = findFactorial(number);
        printf("Factorial of %d = %llu\n", number, result);
    }

    return 0;
}

// Function definition to calculate factorial iteratively
unsigned long long findFactorial(int n) {
    unsigned long long factorial = 1;

    // Loop from 1 to n to calculate the product
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    return factorial;
}
