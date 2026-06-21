#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[100][100];
    int isSymmetric = 1; // Flag variable: 1 means symmetric, 0 means not symmetric

    // 1. Get dimensions from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // 2. A symmetric matrix must be a square matrix
    if (rows != cols) {
        printf("\nThe matrix is NOT symmetric (It must be a square matrix).\n");
        return 0;
    }

    // 3. Input matrix elements
    printf("\nEnter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Print the original matrix for visibility
    printf("\nThe given matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // 5. Check for symmetry
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Compare element with its transposed counterpart
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;          // Break inner loop
            }
        }
        if (!isSymmetric) {
            break; // Break outer loop if already determined as not symmetric
        }
    }

    // 6. Output the final result
    if (isSymmetric == 1) {
        printf("\nConclusion: The matrix is SYMMETRIC.\n");
    } else {
        printf("\nConclusion: The matrix is NOT SYMMETRIC.\n");
    }

    return 0;
}