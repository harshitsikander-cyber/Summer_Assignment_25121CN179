#include <stdio.h>

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max_element = arr[0];
    int max_count = 0;

    // Logic to find the maximum frequency element
    for (int i = 0; i < size; i++) {
        int current_count = 0;

        // Count occurrences of the current element arr[i]
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                current_count++;
            }
        }

        // If the current element's frequency is higher, update tracking variables
        if (current_count > max_count) {
            max_count = current_count;
            max_element = arr[i];
        }
    }

    // Print the final result
    printf("\nElement with maximum frequency: %d\n", max_element);
    printf("It appears %d times.\n", max_count);

    return 0;
}