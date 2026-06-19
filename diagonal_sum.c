#include <stdio.h>

int main() {
    int size;
    int principal_sum = 0;
    int secondary_sum = 0;

    // Get matrix size from the user
    printf("Enter the size of the square matrix (e.g., 3 for 3x3): ");
    scanf("%d", &size);

    int matrix[size][size];

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate diagonal sums using a single efficient loop
    for (int i = 0; i < size; i++) {
        principal_sum += matrix[i][i];             // Main diagonal: row == col
        secondary_sum += matrix[i][size - i - 1]; // Opposite diagonal
    }

    // Print the results
    printf("\n--- Results ---\n");
    printf("Sum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}