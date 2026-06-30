#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure to hold book details
struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued; // 0 = Available, 1 = Issued
};

// Global library variables
struct Book library[MAX_BOOKS];
int book_count = 0;

// Function declarations
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n*** MINI LIBRARY SYSTEM MENU ***");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search for a Book");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit Application");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                printf("\nExiting library system. Goodbye!\n");
                exit(0);
            default:
                printf("\n[Error] Invalid option! Try again.\n");
        }
    }
    return 0;
}

// Function to add a book to the system
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\n[Error] Library is at maximum capacity!\n");
        return;
    }

    struct Book new_book;
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &new_book.id);
    clearInputBuffer(); // Clear leftover newline from buffer

    // Check if Book ID already exists
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("\n[Error] A book with ID %d already exists!\n", new_book.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // Remove newline character

    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // Remove newline character

    new_book.is_issued = 0; // Set status as available

    library[book_count] = new_book;
    book_count++;

    printf("\n[Success] Book added successfully!\n");
}

// Function to display all library inventory
void displayBooks() {
    if (book_count == 0) {
        printf("\nThe library inventory is completely empty.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
    printf("\n-----------------------------------------------------------------------------");
    for (int i = 0; i < book_count; i++) {
        printf("\n%-10d %-30s %-25s %-15s", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n");
}

// Function to search a book using its unique ID
void searchBook() {
    if (book_count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    int search_id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\n--- Book Record Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n[Error] Book with ID %d not found.\n", search_id);
    }
}

// Function to borrow/issue a book
void issueBook() {
    int issue_id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            found = 1;
            if (library[i].is_issued == 1) {
                printf("\n[Error] Book is already checked out to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("\n[Success] Book '%s' issued successfully!\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\n[Error] Book ID not found in inventory.\n");
    }
}

// Function to safely return an issued book
void returnBook() {
    int return_id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            found = 1;
            if (library[i].is_issued == 0) {
                printf("\n[Warning] This book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("\n[Success] Book '%s' returned safely!\n", library[i].title);
            }
            break;
        }
    }

    if (!found) {
        printf("\n[Error] Book ID does not exist.\n");
    }
}

// Utility function to prevent input/buffer corruption bugs
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}