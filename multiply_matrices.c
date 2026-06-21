#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int a[10][10], b[10][10], result[10][10];

    // Input dimensions and validate for matrix multiplication
    printf("Enter rows and cols for 1st matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and cols for 2nd matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error! Column 1 must equal Row 2.\n");
        return 1; // Exit if invalid
    }

    // Input elements and calculate product using nested loops
    // ... [Input code omitted for brevity] ...
    
    // Core Logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // ... [Output code omitted for brevity] ...
    return 0;
}