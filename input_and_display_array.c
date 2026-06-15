#include <stdio.h>

int main() {
    int size, i;

    // Ask the user for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size]; // Declare array with the user-defined size

    // Input array elements
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display array elements
    printf("\nThe elements in the array are:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}