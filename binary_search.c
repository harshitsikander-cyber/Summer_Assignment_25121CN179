#include <stdio.h>

// Function to perform iterative binary search
int binarySearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Prevent potential integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (array[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (array[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Element was not present in the array
    return -1;
}

int main() {
    // Input array must be sorted in ascending order
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 7;

    int result = binarySearch(array, size, target);

    if (result == -1) {
        printf("Element %d is not present in the array.\n", target);
    } else {
        printf("Element %d is found at index: %d\n", target, result);
    }

    return 0;
}