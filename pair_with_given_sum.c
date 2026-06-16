#include <stdio.h>
#include <stdlib.h>

// Comparison function needed for the built-in qsort function
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find and print the pair with the given target sum
void findPairWithSum(int arr[], int size, int targetSum) {
    // Step 1: Sort the array in ascending order
    qsort(arr, size, sizeof(int), compare);

    // Step 2: Initialize two pointers at opposite ends of the array
    int left = 0;
    int right = size - 1;
    int pairFound = 0;

    // Step 3: Loop until the two pointers meet
    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == targetSum) {
            printf("Pair found: [%d, %d]\n", arr[left], arr[right]);
            pairFound = 1;
            
            // Move both pointers to look for other unique combinations
            left++;
            right--;
        } 
        // If the sum is too small, move the left pointer to increase it
        else if (currentSum < targetSum) {
            left++;
        } 
        // If the sum is too large, move the right pointer to decrease it
        else {
            right--;
        }
    }

    if (!pairFound) {
        printf("No pair found with the given sum %d.\n", targetSum);
    }
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int targetSum = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Target Sum: %d\n", targetSum);
    findPairWithSum(arr, size, targetSum);

    return 0;
}