#include <stdio.h>

int main() {
    int size, i;
    int even_count = 0, odd_count = 0;

    // Get array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    // Read values into the array
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Process elements using modulus logic
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Output final results
    printf("Even elements count: %d\n", even_count);
    printf("Odd elements count: %d\n", odd_count);

    return 0;
}
