#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int size1, size2, total_size;
    int i;

    // 1. Get elements for the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements:\n", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 2. Get elements for the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements:\n", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // 3. Copy the first array into the merged array
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    // 4. Append the second array into the merged array
    for (i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    // Calculate total size of the new array
    total_size = size1 + size2;

    // 5. Print the merged array
    printf("\nThe merged array is:\n");
    for (i = 0; i < total_size; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}