#include <stdio.h>

void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}

int main() {
    int myArray[] = {7, 8, 9, 10};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    
    reverseArray(myArray, size);
    
    printf("Reversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    return 0;
}