#include <stdio.h>
#include <math.h>

// Function declarations
int countDigits(int num);
int isArmstrong(int num);

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Call the function and display the result
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is NOT an Armstrong number.\n", number);
    }

    return 0;
}

/**
 * Helper function to count the total number of digits in an integer.
 */
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

/**
 * Function to check whether a given number is an Armstrong number.
 * Returns 1 if true, 0 if false.
 */
int isArmstrong(int num) {
    int originalNum = num;
    int totalDigits = countDigits(num);
    int sum = 0;

    while (num != 0) {
        int remainder = num % 10;
        
        // Use round() to protect against precision loss with pow() floating-point math
        sum += (int)round(pow(remainder, totalDigits));
        
        num /= 10;
    }

    // Check if the sum matches the original input
    return (sum == originalNum);
}