#include <stdio.h>

int main() {
    int rows = 5; // Number of rows for the requested pattern

    // Outer loop handles the number of rows
    for (int i = rows; i >= 1; i--) {
        
        // Inner loop 1: Prints the leading spaces
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }
        
        // Inner loop 2: Prints the asterisks
        for (int k = 0; k < (2 * i - 1); k++) {
            printf("*");
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
