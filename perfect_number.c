#include <stdio.h>

int main() {
    int num, sum = 0;

    // Prompt user for input
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Negative numbers, 0, and 1 cannot be perfect numbers
    if (num <= 1) {
        printf("%d is not a perfect number.\n", num);
        return 0;
    }

    // Find divisors up to num/2 and add them to sum
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors equals the original number
    if (sum == num) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}