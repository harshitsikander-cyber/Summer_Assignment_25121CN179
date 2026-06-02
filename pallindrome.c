#include <stdio.h>

int main() {
    int num, originalNum, remainder;
    int reversedNum = 0;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Store the original number for later comparison
    originalNum = num;

    // Reverse the digits of the integer
    while (num != 0) {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num /= 10;
    }

    // Verify if the reversed number matches the original number
    if (originalNum == reversedNum) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }

    return 0;
}