#include <stdio.h>

// Function declaration
unsigned long long factorial(int n);

int main() {
    int num;
    unsigned long long fact;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Error handling for negative numbers
    if (num < 0) {
        printf("Error: Factorial of a negative number is not defined.\n");
    } else if (num > 20) {
        printf("Error: Input too large. Maximum supported input is 20.\n");
    } else {
        fact = factorial(num);
        printf("Factorial of %d = %llu\n", num, fact);
    }

    return 0;
}

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!
    return n * factorial(n - 1);
}