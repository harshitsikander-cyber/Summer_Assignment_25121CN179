#include <stdio.h>
int main() {
    int n, factorial = 1;
    
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    // Calculate factorial
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    
    printf("Factorial of %d is %d\n", n, factorial);
    
    return 0;
}