#include <stdio.h>

int main() {
    int i, j, rows;

    // Ask user for the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop for rows
    for (i = 1; i <= rows; i++) {
        // Inner loop to print numbers in each row
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}