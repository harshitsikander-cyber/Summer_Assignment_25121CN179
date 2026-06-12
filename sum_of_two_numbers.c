#include <stdio.h>

// Function declaration (prototype)
int sum(int a, int b);

int main() {
    int num1, num2, result;

    // Taking input from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calling the function and storing the returned value
    result = sum(num1, num2);

    // Displaying the result
    printf("The sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

// Function definition to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}