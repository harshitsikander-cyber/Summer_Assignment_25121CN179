#include <stdio.h>

// Function to find the missing number
int findMissingSumMethod(int arr[], int size) {
    // If array has 'size' elements, the sequence contains 'size + 1' total numbers
    int n = size + 1; 
    
    // Calculate expected sum of 1 to n
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    // Calculate the sum of elements present in the array
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    // The difference is the missing number
    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6}; // 3 is missing here
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNum = findMissingSumMethod(arr, size);
    printf("The missing number is: %d\n", missingNum);

    return 0;
}