#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to store Employee details
struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

// Global array and counter to track active records
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee Record\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// 1. Add a new employee record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Database full! Cannot add more records.\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    // Basic validation to prevent duplicate IDs
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID %d already exists.\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); // Clear the buffer newline left by scanf
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    // Save into the array
    employees[employeeCount] = emp;
    employeeCount++;

    printf("Employee added successfully!\n");
}

// 2. Display all records
void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s $%-9.2f\n", 
               employees[i].id, employees[i].name, 
               employees[i].department, employees[i].salary);
    }
}

// 3. Find a specific record
void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: $%.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", searchId);
}

// 4. Remove a record
void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int deleteId;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == deleteId) {
            // Shift remaining records forward to fill the gap
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee record deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", deleteId);
}