#include <stdio.h>

int main() {
    int n, i, j, temp;

    // Ask user for the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read the array elements from the user
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Outer loop to iterate through the entire array
    for (i = 0; i < n; i++) {
        // Inner loop to compare the current element with subsequent elements
        for (j = i + 1; j < n; j++) {
            // Swap if the element at index i is less than the element at index j
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("\nArray sorted in descending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}