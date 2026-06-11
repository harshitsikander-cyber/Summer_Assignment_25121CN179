#include <stdio.h>

int main() {
    int i, j;
    int size = 5; // Size of the square matrix

    // Outer loop for rows
    for (i = 1; i <= size; i++) {
        // Inner loop for columns
        for (j = 1; j <= size; j++) {
            // Print star for boundaries: first/last row or first/last column
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                printf(" "); // Print space for the hollow center
            }
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}