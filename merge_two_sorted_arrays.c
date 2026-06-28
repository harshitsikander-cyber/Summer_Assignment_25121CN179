#include <stdio.h>

// Function to merge two sorted arrays into a third array
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; // Initial index of first array
    int j = 0; // Initial index of second array
    int k = 0; // Initial index of merged array

    // Traverse both arrays and copy the smaller element into merged[]
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1[], if any
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2[], if any
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    // Example sorted arrays
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // The size of the merged array must be the sum of sizes of both arrays
    int merged[n1 + n2];

    // Call the merge function
    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    // Print the result
    printf("Merged Sorted Array:\n");
    for (int idx = 0; idx < n1 + n2; idx++) {
        printf("%d ", merged[idx]);
    }
    printf("\n");

    return 0;
}