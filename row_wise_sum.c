#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[100][100];
    int i, j, rowSum;

    // Input dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input elements of the matrix
    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and display row-wise sum
    printf("\n--- Row-wise Sums ---\n");
    for (i = 0; i < rows; i++) {
        rowSum = 0; // Reset sum for each new row
        for (j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of elements in Row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}
