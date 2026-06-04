#include <stdio.h>

int main() {
    int n;
    // The first two terms of the Fibonacci series are always 0 and 1
    unsigned long long first = 0, second = 1, next;

    printf("Enter the number of terms to generate: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        // Print the current term
        printf("%llu", first);
        
        // Formatting with commas between numbers
        if (i < n) {
            printf(", ");
        }

        // Compute the next term in the sequence
        next = first + second;
        
        // Shift variables left for the next iteration
        first = second;
        second = next;
    }

    printf("\n");
    return 0;
}