#include <stdio.h>

int main() {
    int rows = 5;
    int i, j;

    // Outer loop for the number of rows
    for (i = 1; i <= rows; i++) {
        // Inner loop to print the number in each row
        for (j = 1; j <= i; j++) {
            printf("%d", i);
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}
