#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, temp;
    long long product = 1;

    printf("Enter any integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Store original number for output and handle negative numbers
    temp = num;
    num = abs(num);

    // Handle the specific case where the input is 0
    if (num == 0) {
        product = 0;
    } else {
        while (num > 0) {
            product *= (num % 10); // Extract last digit and multiply
            num /= 10;            // Remove the last digit
        }
    }

    printf("The product of the digits of %d is: %lld\n", temp, product);

    return 0;
}
