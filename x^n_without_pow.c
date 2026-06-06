#include <stdio.h>


double calculate_power(double x, int n) {
    double result = 1.0;
    long long abs_n = n; 

    
    if (abs_n < 0) {
        abs_n = -abs_n;
    }

    
    for (long long i = 0; i < abs_n; i++) {
        result *= x;
    }

    
    if (n < 0) {
        return 1.0 / result;
    }

    return result;
}

int main() {
    double x;
    int n;

    
    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input for base.\n");
        return 1;
    }

    printf("Enter exponent (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for exponent.\n");
        return 1;
    }

    
    if (x == 0.0 && n <= 0) {
        if (n == 0) {
            printf("0^0 is mathematically undefined, but often treated as 1.0\n");
        } else {
            printf("Error: Division by zero (0 raised to a negative power).\n");
            return 1;
        }
    }

    
    double ans = calculate_power(x, n);
    printf("%.4f^%d = %.6f\n", x, n, ans);

    return 0;
}