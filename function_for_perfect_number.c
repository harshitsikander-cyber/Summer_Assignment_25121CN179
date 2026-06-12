#include <stdio.h>

/* Function declaration */
int isPerfect(int num);

int main() {
    int number;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Call the function and check the result */
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}

/**
 * Function: isPerfect
 * Purpose: Checks if a given number is a perfect number.
 * Returns: 1 if perfect, 0 otherwise.
 */
int isPerfect(int num) {
    /* Numbers less than or equal to 0 cannot be perfect numbers */
    if (num <= 0) {
        return 0;
    }

    int sum = 0;

    /* 
     * Loop from 1 to num/2. 
     * No proper divisor can be greater than half of the number.
     */
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; /* Add divisor to sum */
        }
    }

    /* If sum of proper divisors equals the original number, it is perfect */
    if (sum == num) {
        return 1; 
    } else {
        return 0;
    }
}