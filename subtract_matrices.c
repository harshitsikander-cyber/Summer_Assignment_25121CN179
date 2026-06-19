#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int first[10][10], second[10][10], difference[10][10];

    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input elements for the first matrix
    printf("\nEnter elements of the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &first[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements of the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &second[i][j]);
        }
    }

    // Perform matrix subtraction
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            difference[i][j] = first[i][j] - second[i][j];
        }
    }

    // Display the result matrix
    printf("\nResultant Matrix (First - Second):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}