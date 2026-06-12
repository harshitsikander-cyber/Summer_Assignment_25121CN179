#include <stdio.h>

// Function declaration
int find_maximum(int num1, int num2);

int main() {
    int a, b, max;

    // Requesting user input
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Calling the function to get the maximum value
    max = find_maximum(a, b);

    // Displaying the result
    printf("The maximum value is: %d\n", max);

    return 0;
}

// Function definition to find the maximum of two numbers
int find_maximum(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}