#include <stdio.h>
#include <stdbool.h>

// Function to check if an element is already present in the array
bool isPresent(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

// Function to find the union of two arrays
int findUnion(int arr1[], int size1, int arr2[], int size2, int unionArr[]) {
    int unionSize = 0;

    // Copy unique elements from the first array to the union array
    for (int i = 0; i < size1; i++) {
        if (!isPresent(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    // Copy unique elements from the second array to the union array
    for (int i = 0; i < size2; i++) {
        if (!isPresent(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    return unionSize;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 2, 6};
    int arr2[] = {2, 3, 5, 7, 8, 4};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // The maximum possible size of the union array is the sum of both sizes
    int unionArr[size1 + size2]; 
    
    int unionSize = findUnion(arr1, size1, arr2, size2, unionArr);
    
    // Print the final result
    printf("Union of the two arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
    
    return 0;
}