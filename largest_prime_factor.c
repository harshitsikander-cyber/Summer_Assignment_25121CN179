#include <stdio.h>

// Function to find the largest prime factor
long long get_largest_prime_factor(long long n) {
    long long max_prime = -1;

    
    while (n % 2 == 0) {
        max_prime = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n /= i;
        }
    }


    if (n > 2) {
        max_prime = n;
    }

    return max_prime;
}

int main() {
    long long num;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 1) {
        printf("Please enter a valid integer greater than 1.\n");
        return 1;
    }

    long long result = get_largest_prime_factor(num);
    printf("The largest prime factor of %lld is: %lld\n", num, result);

    return 0;
}