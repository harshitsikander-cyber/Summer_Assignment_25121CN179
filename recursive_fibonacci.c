#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    // Get the number of terms from the user
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);

    // Validate input to ensure positive integer values
    if (terms <= 0) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    printf("Fibonacci Series: ");
    // Loop through each index to print the complete sequence
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}