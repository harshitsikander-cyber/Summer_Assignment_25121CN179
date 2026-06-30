#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to define a student record
struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    float marks;
};

// Function prototypes
void addStudentRecord(struct Student students[], int *count);
void displayAllRecords(const struct Student students[], int count);
void searchStudentRecord(const struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        // Read choice and clear newline from the buffer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        getchar(); // Consume trailing newline

        switch (choice) {
            case 1:
                addStudentRecord(database, &studentCount);
                break;
            case 2:
                displayAllRecords(database, studentCount);
                break;
            case 3:
                searchStudentRecord(database, studentCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// 1. Add a new student record
void addStudentRecord(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nError: Database is full! Cannot add more records.\n");
        return;
    }

    struct Student newStudent;

    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.roll_no);
    getchar(); // Clear trailing newline from buffer

    printf("Enter Full Name: ");
    // fgets reads strings safely with spaces included
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    // Remove the trailing newline character added by fgets
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter Total Marks: ");
    scanf("%f", &newStudent.marks);
    getchar(); // Clear trailing newline

    // Save the temporary structure into our database array
    students[*count] = newStudent;
    (*count)++; // Increment total count

    printf("Record added successfully!\n");
}

// 2. Display all active records
void displayAllRecords(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found in the database.\n");
        return;
    }

    printf("\n------------------------------------------------------\n");
    printf("%-10s | %-30s | %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d | %-30s | %-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    printf("------------------------------------------------------\n");
}

// 3. Search for a specific record
void searchStudentRecord(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nDatabase empty. Nothing to search.\n");
        return;
    }

    int targetRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == targetRoll) {
            printf("\n--- Record Found ---\n");
            printf("Roll Number: %d\n", students[i].roll_no);
            printf("Name:        %s\n", students[i].name);
            printf("Marks:       %.2f\n", students[i].marks);
            found = 1;
            break; // Stop loop once match is found
        }
    }

    if (!found) {
        printf("\nRecord with Roll Number %d not found.\n", targetRoll);
    }
}