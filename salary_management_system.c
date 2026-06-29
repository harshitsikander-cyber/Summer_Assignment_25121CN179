#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to hold employee and salary details
struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;          // House Rent Allowance
    float da;           // Dearness Allowance
    float pf;           // Provident Fund Deduction
    float gross_salary;
    float net_salary;
};

// Function prototypes
void addEmployee(struct Employee emp[], int *count);
void displayAll(struct Employee emp[], int count);
void searchEmployee(struct Employee emp[], int count);
void calculateSalary(struct Employee *emp);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    SALARY MANAGEMENT SYSTEM     ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. Display All Salary Records");
        printf("\n3. Search Employee Payslip");
        printf("\n4. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addEmployee(employees, &employee_count);
                break;
            case 2:
                displayAll(employees, employee_count);
                break;
            case 3:
                searchEmployee(employees, employee_count);
                break;
            case 4:
                printf("\nThank you for using the system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to automatically compute breakdown metrics
void calculateSalary(struct Employee *emp) {
    // Breakdown formulas: HRA (20%), DA (10%), PF (12%)
    emp->hra = emp->basic_salary * 0.20;
    emp->da = emp->basic_salary * 0.10;
    emp->pf = emp->basic_salary * 0.12;
    
    // Earnings before deductions
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    
    // Final take-home pay
    emp->net_salary = emp->gross_salary - emp->pf;
}

// Function to append a new record
void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: System storage full!\n");
        return;
    }

    struct Employee new_emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &new_emp.id);
    
    // Consume trailing newline character
    getchar(); 
    
    printf("Enter Employee Name: ");
    fgets(new_emp.name, sizeof(new_emp.name), stdin);
    new_emp.name[strcspn(new_emp.name, "\n")] = 0; // Strip newline

    printf("Enter Basic Salary: ");
    scanf("%f", &new_emp.basic_salary);

    // Compute metrics
    calculateSalary(&new_emp);

    // Save to tracking array
    emp[*count] = new_emp;
    (*count)++;

    printf("\nRecord added successfully!\n");
}

// Function to output summary matrix
void displayAll(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records found to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-12s %-10s %-10s %-10s %-12s", 
           "ID", "Name", "Basic", "HRA", "DA", "PF", "Net Salary");
    printf("\n---------------------------------------------------------------------------------");
    
    for (int i = 0; i < count; i++) {
        printf("\n%-5d %-20s %-12.2f %-10.2f %-10.2f %-10.2f %-12.2f", 
               emp[i].id, emp[i].name, emp[i].basic_salary, 
               emp[i].hra, emp[i].da, emp[i].pf, emp[i].net_salary);
    }
    printf("\n---------------------------------------------------------------------------------\n");
}

// Function to isolate individual payslips
void searchEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int search_id;
    int found = 0;
    
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == search_id) {
            found = 1;
            printf("\n=================================");
            printf("\n        EMPLOYEE PAYSLIP         ");
            printf("\n=================================");
            printf("\nID             : %d", emp[i].id);
            printf("\nName           : %s", emp[i].name);
            printf("\nBasic Salary   : $%.2f", emp[i].basic_salary);
            printf("\nHRA (20%%)      : $%.2f", emp[i].hra);
            printf("\nDA (10%%)       : $%.2f", emp[i].da);
            printf("\nGross Salary   : $%.2f", emp[i].gross_salary);
            printf("\nPF Deduction   : $%.2f", emp[i].pf);
            printf("\n---------------------------------");
            printf("\nNET PAYOUT     : $%.2f", emp[i].net_salary);
            printf("\n=================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee Record with ID %d not found.\n", search_id);
    }
}