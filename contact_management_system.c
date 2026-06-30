#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

// Define the structure for a single contact
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    CONTACT MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Contact");
        printf("\n2. View All Contacts");
        printf("\n3. Search Contact By Name");
        printf("\n4. Edit a Contact");
        printf("\n5. Delete a Contact");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clear newline character left by scanf

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("\nExiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("\n[Error] Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Helper function to clear leftover keyboard buffer data
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a contact record to the file
void addContact() {
    FILE *file = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (file == NULL) {
        printf("\n[Error] Could not open or create data file.\n");
        return;
    }

    Contact newContact;

    printf("\nEnter Name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter Phone Number: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("Enter Email Address: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    fwrite(&newContact, sizeof(Contact), 1, file);
    fclose(file);

    printf("\n[Success] Contact saved successfully!\n");
}

// 2. Read and print all contacts inside the file
void viewContacts() {
    FILE *file = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (file == NULL) {
        printf("\n[Info] No contacts found. The contact list is empty.\n");
        return;
    }

    Contact currentContact;
    int count = 1;

    printf("\n====================================================================\n");
    printf("%-5s | %-20s | %-15s | %-25s\n", "S.No", "Name", "Phone", "Email");
    printf("====================================================================\n");

    while (fread(&currentContact, sizeof(Contact), 1, file) == 1) {
        printf("%-5d | %-20s | %-15s | %-25s\n", 
               count++, currentContact.name, currentContact.phone, currentContact.email);
    }
    
    printf("====================================================================\n");
    fclose(file);
}

// 3. Look up a contact matching a specific name
void searchContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\n[Info] No contacts available to search.\n");
        return;
    }

    char searchName[50];
    Contact currentContact;
    int found = 0;

    printf("\nEnter the Name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (fread(&currentContact, sizeof(Contact), 1, file) == 1) {
        // Case-insensitive comparison fallback or exact comparison
        if (strcasecmp(currentContact.name, searchName) == 0) {
            if (!found) {
                printf("\n[Match Found]:\n");
            }
            printf("---------------------------------\n");
            printf("Name : %s\n", currentContact.name);
            printf("Phone: %s\n", currentContact.phone);
            printf("Email: %s\n", currentContact.email);
            found = 1;
        }
    }

    if (!found) {
        printf("\n[Info] No contact matching '%s' was found.\n", searchName);
    } else {
        printf("---------------------------------\n");
    }

    fclose(file);
}

// 4. Modify fields of an existing contact record
void editContact() {
    FILE *file = fopen(FILE_NAME, "rb+"); // Read and write mode
    if (file == NULL) {
        printf("\n[Info] No contacts available to edit.\n");
        return;
    }

    char targetName[50];
    Contact currentContact;
    int found = 0;

    printf("\nEnter the exact Name of the contact to edit: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    while (fread(&currentContact, sizeof(Contact), 1, file) == 1) {
        if (strcasecmp(currentContact.name, targetName) == 0) {
            found = 1;
            printf("\n[Current Details Found]:\n");
            printf("Name: %s | Phone: %s | Email: %s\n", currentContact.name, currentContact.phone, currentContact.email);
            
            printf("\nEnter New Name: ");
            fgets(currentContact.name, sizeof(currentContact.name), stdin);
            currentContact.name[strcspn(currentContact.name, "\n")] = '\0';

            printf("Enter New Phone: ");
            fgets(currentContact.phone, sizeof(currentContact.phone), stdin);
            currentContact.phone[strcspn(currentContact.phone, "\n")] = '\0';

            printf("Enter New Email: ");
            fgets(currentContact.email, sizeof(currentContact.email), stdin);
            currentContact.email[strcspn(currentContact.email, "\n")] = '\0';

            // Shift file position pointer backwards by one record size to overwrite it
            fseek(file, -sizeof(Contact), SEEK_CUR);
            fwrite(&currentContact, sizeof(Contact), 1, file);
            printf("\n[Success] Contact updated successfully!\n");
            break; 
        }
    }

    if (!found) {
        printf("\n[Error] Contact named '%s' does not exist.\n", targetName);
    }

    fclose(file);
}

// 5. Delete a contact by skipping it while copying others to a temporary file
void deleteContact() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("\n[Info] No contacts available to delete.\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        printf("\n[Error] Internal error creating a temporary file.\n");
        fclose(file);
        return;
    }

    char targetName[50];
    Contact currentContact;
    int deleted = 0;

    printf("\nEnter the exact Name of the contact to delete: ");
    fgets(targetName, sizeof(targetName), stdin);
    targetName[strcspn(targetName, "\n")] = '\0';

    while (fread(&currentContact, sizeof(Contact), 1, file) == 1) {
        if (strcasecmp(currentContact.name, targetName) == 0) {
            deleted = 1; // Mark as deleted, skip writing to temp file
            continue;
        }
        fwrite(&currentContact, sizeof(Contact), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    if (deleted) {
        remove(FILE_NAME);             // Remove old database file
        rename("temp.dat", FILE_NAME); // Promote temp file to main database
        printf("\n[Success] Contact successfully deleted!\n");
    } else {
        remove("temp.dat");            // Clean up unused temp file
        printf("\n[Info] No contact named '%s' was found.\n", targetName);
    }
}