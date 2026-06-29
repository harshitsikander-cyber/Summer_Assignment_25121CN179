#include <stdio.h>
#include <string.h>

#define NUM_SUBJECTS 5

// Structure to hold student details and marks
struct Student {
    char name[50];
    int rollNumber;
    char course[30];
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float percentage;
    char grade[3];
    char status[5];
};

// Function declarations
void calculateResults(struct Student *s);
void displayMarksheet(struct Student s, const char subjectNames[NUM_SUBJECTS][30]);

int main() {
    struct Student s1;
    
    // Hardcoded subject names for uniform evaluation
    const char subjects[NUM_SUBJECTS][30] = {
        "Mathematics",
        "Physics",
        "Chemistry",
        "Computer Science",
        "English"
    };

    // User Data Input
    printf("===========================================\n");
    printf("        MARKSHEET GENERATION SYSTEM        \n");
    printf("===========================================\n");
    
    printf("Enter Student Full Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0; // Remove trailing newline characters

    printf("Enter Roll Number: ");
    scanf("%d", &s1.rollNumber);
    
    printf("Enter Course/Class: ");
    getchar(); // Clear the input buffer
    fgets(s1.course, sizeof(s1.course), stdin);
    s1.course[strcspn(s1.course, "\n")] = 0;

    printf("\n--- Enter Marks Obtained (Out of 100) ---\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        do {
            printf("%s: ", subjects[i]);
            scanf("%d", &s1.marks[i]);
            if (s1.marks[i] < 0 || s1.marks[i] > 100) {
                printf("[Error] Marks must remain between 0 and 100. Retry.\n");
            }
        } while (s1.marks[i] < 0 || s1.marks[i] > 100);
    }

    // Process performance and metrics
    calculateResults(&s1);

    // Render formatted output
    displayMarksheet(s1, subjects);

    return 0;
}

// Logical calculation engine
void calculateResults(struct Student *s) {
    s->totalMarks = 0;
    int failedA_Subject = 0;

    // Sum scores and scan for individual passing criteria (Minimum 33 per subject)
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->totalMarks += s->marks[i];
        if (s->marks[i] < 33) {
            failedA_Subject = 1;
        }
    }

    // Percentage logic out of maximum 500 potential points
    s->percentage = (float)s->totalMarks / NUM_SUBJECTS;

    // Pass / Fail filtering
    if (failedA_Subject) {
        strcpy(s->status, "FAIL");
        strcpy(s->grade, "F");
    } else {
        strcpy(s->status, "PASS");
        
        // Tiered Grade Assignment
        if (s->percentage >= 90) strcpy(s->grade, "A+");
        else if (s->percentage >= 80) strcpy(s->grade, "A");
        else if (s->percentage >= 70) strcpy(s->grade, "B");
        else if (s->percentage >= 60) strcpy(s->grade, "C");
        else if (s->percentage >= 50) strcpy(s->grade, "D");
        else strcpy(s->grade, "E");
    }
}

// Console layout render engine
void displayMarksheet(struct Student s, const char subjectNames[NUM_SUBJECTS][30]) {
    printf("\n\n");
    printf("############################################################\n");
    printf("#                    OFFICIAL MARKSHEET                    #\n");
    printf("############################################################\n");
    printf("  Student Name : %-25s Roll No: %-10d\n", s.name, s.rollNumber);
    printf("  Course/Class : %-40s\n", s.course);
    printf("------------------------------------------------------------\n");
    printf("  %-25s | %-15s | %-10s\n", "SUBJECT", "MAX MARKS", "OBTAINED");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("  %-25s | %-15d | %-10d %s\n", 
               subjectNames[i], 100, s.marks[i], (s.marks[i] < 33) ? "*" : "");
    }
    
    printf("------------------------------------------------------------\n");
    printf("  Aggregate Total: %d / %d\n", s.totalMarks, NUM_SUBJECTS * 100);
    printf("  Final Percentage: %.2f%%\n", s.percentage);
    printf("  Assigned Grade  : %s\n", s.grade);
    printf("  Academic Status : %s %s\n", s.status, (strcmp(s.status, "FAIL") == 0) ? "(* Remedial required)" : "");
    printf("############################################################\n");
}