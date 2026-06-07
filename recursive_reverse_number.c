#include <stdio.h>

// Recursive function to reverse the digits of a number
int reverseNumber(int num, int rev) {
    // Base Case: when the remaining number becomes 0, return the accumulated reverse
    if (num == 0) {
        return rev;
    }
    
    // Extract the last digit and append it to the accumulated result
    rev = (rev * 10) + (num % 10);
    
    // Recursive Call: pass the remaining number and the updated result
    return reverseNumber(num / 10, rev);
}

int main() {
    int number, reversed;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the recursive function starting with an initial accumulated value of 0
    reversed = reverseNumber(number, 0);

    printf("Reversed number: %d\n", reversed);

    return 0;
}