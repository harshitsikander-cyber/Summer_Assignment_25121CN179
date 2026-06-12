#include <stdio.h>

// Function declaration to print Fibonacci series up to n terms
void printFibonacciIterative(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two terms are 0 and 1
        } else {
            next = first + second; // Calculate next term
            first = second;        // Shift backward variables
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
    } else {
        printFibonacciIterative(terms);
    }

    return 0;
}
