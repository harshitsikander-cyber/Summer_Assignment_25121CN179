#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Function prototypes
void displayMenu();
void addStudent(int rollNumbers[], char names[][NAME_LENGTH], int *count);
void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], int count);
void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], int count);

int main() {
    // Arrays to store student records
    int rollNumbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_LENGTH];
    int studentCount = 0;
    int choice;

    printf("=== Welcome to the Student Database System ===\n");

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        // Clean newline buffer left by scanf
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                addStudent(rollNumbers, names, &studentCount);
                break;
            case 2:
                displayStudents(rollNumbers, names, studentCount);
                break;
            case 3:
                searchStudent(rollNumbers, names, studentCount);
                break;
            case 4:
                printf("\nThank you for using the system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to print the application options menu
void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Exit Application\n");
}

// Function to add a student record to our data arrays
void addStudent(int rollNumbers[], char names[][NAME_LENGTH], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: Database memory is full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNumbers[*count]);
    while (getchar() != '\n'); // Clean buffer

    printf("Enter Student Name: ");
    // Safely read a string with spaces up to buffer limits
    fgets(names[*count], NAME_LENGTH, stdin);
    
    // Strip trailing newline added by fgets
    names[*count][strcspn(names[*count], "\n")] = '\0';

    (*count)++;
    printf("Success: Student added successfully!\n");
}

// Function to clear through arrays and display all data values
void displayStudents(const int rollNumbers[], const char names[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo student records found in the database.\n");
        return;
    }

    printf("\n%-15s %-30s\n", "Roll Number", "Student Name");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15d %-30s\n", rollNumbers[i], names[i]);
    }
}

// Function to search for data inside arrays using a target element
void searchStudent(const int rollNumbers[], const char names[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetRoll;
    int foundIndex = -1;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    // Linear search execution
    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == targetRoll) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("\nRecord Found!\n");
        printf("Roll Number: %d\n", rollNumbers[foundIndex]);
        printf("Name       : %s\n", names[foundIndex]);
    } else {
        printf("\nRecord not found for Roll Number %d.\n", targetRoll);
    }
}