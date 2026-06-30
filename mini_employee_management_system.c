#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();
void updateEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== MINI EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee Record\n");
        printf("5. Update Employee Salary/Designation\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: updateEmployee(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Add a new employee record to the binary file
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // Clear trailing newline character

    printf("Enter Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("Employee record added successfully!\n");
}

// 2. Read and print all records from the binary file
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo employee records found. Please add a record first.\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------------\n");

    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-20s $%-9.2f\n", emp.id, emp.name, emp.designation, emp.salary);
    }
    fclose(fp);
}

// 3. Find a specific employee using their unique ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == searchId) {
            printf("\n--- Record Found ---\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Designation: %s\n", emp.designation);
            printf("Salary: $%.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

// 4. Delete an employee record by recreating the database file without the specified ID
void deleteEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    // Create a temporary file to hold data we want to keep
    FILE *tempFp = fopen("temp.dat", "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == deleteId) {
            found = 1; // Record skipped (deleted)
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFp); // Keep record
        }
    }
    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);             // Remove old file
        rename("temp.dat", FILE_NAME); // Rename temp file to original name
        printf("Employee record deleted successfully!\n");
    } else {
        remove("temp.dat"); // Delete temp file if no matching ID found
        printf("Employee with ID %d not found.\n", deleteId);
    }
}

// 5. Update data fields of an existing employee record
void updateEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    if (fp == NULL) {
        printf("\nNo employee records found.\n");
        return;
    }

    int updateId, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &updateId);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == updateId) {
            found = 1;
            getchar(); // Clear trailing newline

            printf("Enter New Designation: ");
            fgets(emp.designation, sizeof(emp.designation), stdin);
            emp.designation[strcspn(emp.designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp.salary);

            // Move the file pointer back to the start of this specific record
            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Employee record updated successfully!\n");
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Employee with ID %d not found.\n", updateId);
    }
}