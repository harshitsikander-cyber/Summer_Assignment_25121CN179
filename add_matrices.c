#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // 1. Get matrix dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare 2D arrays with the user-defined dimensions
    int matrixA[rows][cols];
    int matrixB[rows][cols];
    int sumMatrix[rows][cols];

    // 2. Input elements for the first matrix
    printf("\nEnter elements for Matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // 3. Input elements for the second matrix
    printf("\nEnter elements for Matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // 4. Add the corresponding elements of both matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // 5. Display the final resultant matrix
    printf("\nResultant Matrix (A + B):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", sumMatrix[i][j]);
        }
        printf("\n"); // Moves to the next line after printing a full row
    }

    return 0;
}