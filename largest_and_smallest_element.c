#include <stdio.h>

int main() {
    int arr[] = {34, 12, 89, 5, 45, 90, 23};
    // Calculate the total number of elements
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    if (n == 0) {
        printf("Array is empty.\n");
        return 0;
    }

    // Initialize trackers with the first position element
    int smallest = arr[0];
    int largest = arr[0];

    // Loop through the array from the second element
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Output findings
    printf("Smallest element: %d\n", smallest);
    printf("Largest element: %d\n", largest);

    return 0;
}