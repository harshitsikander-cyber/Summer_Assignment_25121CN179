#include <stdio.h>

void decimalToBinary(int n) {
    // Array to store binary digits (32 bits for a standard integer)
    int binaryNum[32];
    int i = 0;

    // Handle the base case where the input number is 0
    if (n == 0) {
        printf("0");
        return;
    }

    // Store remainders in the array
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print the array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    printf("Binary equivalent: ");
    decimalToBinary(decimal);
    printf("\n");
    
    return 0;
}
