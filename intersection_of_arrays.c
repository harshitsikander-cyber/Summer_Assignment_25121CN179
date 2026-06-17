#include <stdio.h>

// Function to check if an element is already added to the intersection array
int isDuplicate(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Found a duplicate
        }
    }
    return 0; // Unique element
}

// Function to find and print the intersection of two arrays
void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    int intersection[100]; // Array to store the matching elements
    int k = 0;             // Index counter for the intersection array

    // Compare every element of the first array with the second array
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                // Check if the common element is already added to avoid repeating it
                if (!isDuplicate(intersection, k, arr1[i])) {
                    intersection[k] = arr1[i];
                    k++;
                }
                break; // Move to the next element in arr1 once a match is found
            }
        }
    }

    // Print the final intersection results
    if (k == 0) {
        printf("No common elements found.\n");
    } else {
        printf("Intersection of the two arrays: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example data
    int arr1[] = {4, 9, 1, 9, 2, 4};
    int arr2[] = {9, 5, 4, 4, 3};
    
    // Calculate sizes dynamically
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Array 1: ");
    for(int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    printf("\n");

    printf("Array 2: ");
    for(int i = 0; i < size2; i++) printf("%d ", arr2[i]);
    printf("\n\n");

    // Call the intersection function
    findIntersection(arr1, size1, arr2, size2);

    return 0;
}