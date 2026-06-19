#include <stdio.h>
#include <stdbool.h>

// Function to perform optimized bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    bool swapped;
    
    // Outer loop for the number of passes
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Inner loop for adjacent element comparisons
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped by inner loop, then break
        if (swapped == false) {
            break;
        }
    }
}

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array:\n");
    printArray(data, n);
    
    bubbleSort(data, n);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, n);
    
    return 0;
}