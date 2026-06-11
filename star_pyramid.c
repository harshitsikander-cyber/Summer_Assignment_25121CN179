#include <stdio.h>

int main() {
    int rows, i, j, k;

    // Ask the user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop handles the total number of rows
    for (i = 1; i <= rows; i++) {
        
        // First inner loop prints the leading white spaces
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Second inner loop prints the odd number of stars (2*i - 1)
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }

        // Move to the next line after finishing each row
        printf("\n");
    }

    return 0;
}