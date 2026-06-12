#include <stdio.h>

// Function to check if a number is prime
// Returns 1 if prime, 0 if not prime
int isPrime(int n) {
    // Numbers less than or equal to 1 are not prime
    if (n <= 1) {
        return 0;
    }
    
    // Check divisibility from 2 up to the square root of n
    // Using (i * i <= n) avoids importing the math.h library
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Found a factor, so it is not prime
        }
    }
    
    return 1; // No factors found, it is prime
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the function and print the result
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}