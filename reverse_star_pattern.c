#include <stdio.h>

int main() {
    int rows = 5;

    // Outer loop for rows (starts at maximum and counts down)
    for (int i = rows; i >= 1; i--) {
        
        // Inner loop for columns (prints stars based on current row value)
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}