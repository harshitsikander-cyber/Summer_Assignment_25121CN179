#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void createArray(int arr[], int *size);
void displayArray(const int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(const int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Tracks the current number of elements in the array
    int choice;

    while (1) {
        printf("\n=============================");
        printf("\n   ARRAY OPERATIONS MENU");
        printf("\n=============================");
        printf("\n1. Create / Reset Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Search Element");
        printf("\n6. Exit");
        printf("\n=============================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                createArray(arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                searchElement(arr, size);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Create or populate the array
void createArray(int arr[], int *size) {
    int n;
    printf("\nEnter the number of elements (Max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid size! Size must be between 0 and %d.\n", MAX_SIZE);
        return;
    }

    *size = n;
    if (n > 0) {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < *size; i++) {
            printf("Element [%d]: ", i);
            scanf("%d", &arr[i]);
        }
        printf("Array created successfully.\n");
    }
}

// 2. Display all elements of the array
void displayArray(const int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty nothing to display.\n");
        return;
    }

    printf("\nCurrent Array Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 3. Insert an element at a specific index
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("\nError: Array Overflow! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position index (0 to %d): ", *size);
    scanf("%d", &position);

    // Validation for bounds
    if (position < 0 || position > *size) {
        printf("Invalid position index!\n");
        return;
    }

    // Shift elements to the right to make room
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Place the new element and update the size tracker
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// 4. Delete an element from a specific index
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array Underflow! No elements to delete.\n");
        return;
    }

    int position;
    printf("\nEnter the position index to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    // Validation for bounds
    if (position < 0 || position >= *size) {
        printf("Invalid position index!\n");
        return;
    }

    // Shift elements to the left to close the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Reduce array size tracker
    (*size)--;
    printf("Element deleted successfully.\n");
}

// 5. Look up an element using linear search
void searchElement(const int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty. Nothing to search.\n");
        return;
    }

    int target, found = -1;
    printf("\nEnter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = i;
            break; // Stop at first occurrence
        }
    }

    if (found != -1) {
        printf("Element found at position index: %d\n", found);
    } else {
        printf("Element not found in the array.\n");
    }
}