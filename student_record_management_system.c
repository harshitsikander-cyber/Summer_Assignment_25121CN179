#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define COURSE_LEN 20

// Define the structure to hold student details
typedef struct {
    int rollNumber;
    char name[NAME_LEN];
    float cgpa;
    char course[COURSE_LEN];
} Student;

// Global array and tracking variable
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function Prototypes
void addStudent();
void displayAll();
void searchStudent();
void updateStudent();
void deleteStudent();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n  STUDENT RECORD MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Student Record");
        printf("\n2. Display All Student Records");
        printf("\n3. Search Student by Roll Number");
        printf("\n4. Update Student Record");
        printf("\n5. Delete Student Record");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Add a new student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nDatabase Full! Cannot add more students.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input type!\n");
        clearInputBuffer();
        return;
    }

    // Check for duplicate roll numbers
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("Error: A student with Roll Number %d already exists!\n", roll);
            return;
        }
    }

    students[studentCount].rollNumber = roll;
    clearInputBuffer(); // Clean leftover newline before reading strings

    printf("Enter Full Name: ");
    fgets(students[studentCount].name, NAME_LEN, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0'; // Remove newline character

    printf("Enter Course: ");
    fgets(students[studentCount].course, COURSE_LEN, stdin);
    students[studentCount].course[strcspn(students[studentCount].course, "\n")] = '\0';

    printf("Enter CGPA: ");
    if (scanf("%f", &students[studentCount].cgpa) != 1) {
        printf("Invalid input type! Setting CGPA to 0.0\n");
        students[studentCount].cgpa = 0.0;
    }

    studentCount++;
    printf("\nStudent record added successfully!\n");
}

// 2. Display all records in a structured format
void displayAll() {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------\n");
    printf("%-10s | %-25s | %-15s | %-5s\n", "Roll No", "Name", "Course", "CGPA");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-10d | %-25s | %-15s | %-5.2f\n", 
               students[i].rollNumber, students[i].name, students[i].course, students[i].cgpa);
    }
    printf("-------------------------------------------------------------------\n");
}

// 3. Search for an individual student record
void searchStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nStudent Found!");
            printf("\nRoll Number: %d", students[i].rollNumber);
            printf("\nName:        %s", students[i].name);
            printf("\nCourse:      %s", students[i].course);
            printf("\nCGPA:        %.2f\n", students[i].cgpa);
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}

// 4. Update an existing student record
void updateStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to modify: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nCurrent Record Found. Enter New Details:\n");
            clearInputBuffer();

            printf("Enter New Name: ");
            fgets(students[i].name, NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New Course: ");
            fgets(students[i].course, COURSE_LEN, stdin);
            students[i].course[strcspn(students[i].course, "\n")] = '\0';

            printf("Enter New CGPA: ");
            scanf("%f", &students[i].cgpa);

            printf("\nRecord updated successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}

// 5. Delete a student record from the system
void deleteStudent() {
    if (studentCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == roll) {
            // Shift all subsequent elements one step backwards to fill the empty slot
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("\nStudent with Roll Number %d not found.\n", roll);
}

// Utility function to clear standard input stream buffers
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}