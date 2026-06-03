#include <stdio.h>


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, gcd;

    
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    
    int absNum1 = (num1 < 0) ? -num1 : num1;
    int absNum2 = (num2 < 0) ? -num2 : num2;

    
    gcd = findGCD(absNum1, absNum2);

    
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
