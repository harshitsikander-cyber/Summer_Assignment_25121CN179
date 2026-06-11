#include <stdio.h>

int main() {
    int rows = 5; // Set to 5 for numbers 12345

    // Outer loop for the rows
    for (int i = rows; i >= 1; i--) {
        // Inner loop for printing numbers
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}