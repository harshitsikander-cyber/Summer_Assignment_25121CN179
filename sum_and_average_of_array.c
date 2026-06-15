#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    // Calculate the number of elements in the array
    int length = sizeof(arr) / sizeof(arr[0]); 
    int sum = 0;
    float average;

    // Loop through the array to find the sum
    for(int i = 0; i < length; i++) {
        sum += arr[i];
    }

    // Typecast to float for an accurate decimal average
    average = (float)sum / length; 

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}