#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;

    // Move boundary of unsorted subarray one by one
    for (i = 0; i < size - 1; i++) {
        // Assume the first element of the unsorted part is the minimum
        min_idx = i;

        // Check the rest of the unsorted array to find the true minimum
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 25, 12, 22, 11};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: \n");
    printArray(data, size);

    selectionSort(data, size);

    printf("Sorted array in ascending order: \n");
    printArray(data, size);

    return 0;
}
