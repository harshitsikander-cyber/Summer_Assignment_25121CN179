#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define STR_LEN 50

// Structure to hold book information
typedef struct {
    int id;
    char title[STR_LEN];
    char author[STR_LEN];
    float price;
    int is_issued; // 0 = Available, 1 = Issued
} Book;

// Function prototypes
void displayMenu();
void addBook(Book library[], int *bookCount);
void displayBooks(const Book library[], int bookCount);
void searchBook(const Book library[], int bookCount);
void issueBook(Book library[], int bookCount);
void returnBook(Book library[], int bookCount);
void clearInputBuffer();

int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Consume trailing newline character

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                issueBook(library, bookCount);
                break;
            case 5:
                returnBook(library, bookCount);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

// Displays the dashboard layout
void displayMenu() {
    printf("\n====================================\n");
    printf("     LIBRARY MANAGEMENT SYSTEM      \n");
    printf("====================================\n");
    printf("1. Add a New Book\n");
    printf("2. Display All Books\n");
    printf("3. Search for a Book by Title\n");
    printf("4. Issue a Book\n");
    printf("5. Return a Book\n");
    printf("6. Exit Program\n");
    printf("====================================\n");
}

// Clears the buffer to fix scanf/fgets tracking bugs
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Adds a new book entry safely to the collection
void addBook(Book library[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Error: Library capacity reached. Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Check for ID duplication
    for (int i = 0; i < *bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("Error: A book with ID %d already exists.\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, STR_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(newBook.author, STR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Price: ");
    if (scanf("%f", &newBook.price) != 1) {
        printf("Invalid price format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    newBook.is_issued = 0; // Set status as available initially

    library[*bookCount] = newBook;
    (*bookCount)++;
    printf("Success: Book added successfully!\n");
}

// Lists out all books currently tracked in memory
void displayBooks(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nThe library inventory is currently empty.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s %-12s\n", "Book ID", "Title", "Author", "Price", "Status");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-25s %-20s $%-9.2f %-12s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].price,
               library[i].is_issued ? "Issued" : "Available");
    }
}

// Filters data records based on case-insensitive matches
void searchBook(const Book library[], int bookCount) {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    char searchTitle[STR_LEN];
    printf("\nEnter the title of the book to search: ");
    fgets(searchTitle, STR_LEN, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        // Simple case-sensitive substring match; use strcasecmp if platform supports it
        if (strstr(library[i].title, searchTitle) != NULL) {
            if (!found) {
                printf("\nMatch Found:\n");
                printf("%-10s %-25s %-20s %-10s %-12s\n", "Book ID", "Title", "Author", "Price", "Status");
                printf("----------------------------------------------------------------------------\n");
            }
            printf("%-10d %-25s %-20s $%-9.2f %-12s\n",
                   library[i].id,
                   library[i].title,
                   library[i].author,
                   library[i].price,
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("No book found containing the title \"%s\".\n", searchTitle);
    }
}

// Marks an available book as borrowed
void issueBook(Book library[], int bookCount) {
    int searchId;
    printf("\nEnter Book ID to Issue: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid ID format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            if (library[i].is_issued == 1) {
                printf("Sorry, this book is already issued to someone else.\n");
                return;
            } else {
                library[i].is_issued = 1;
                printf("Success: Book \"%s\" has been successfully issued.\n", library[i].title);
                return;
            }
        }
    }
    printf("Error: Book with ID %d not found.\n", searchId);
}

// Updates an issued book status back to safe keeping
void returnBook(Book library[], int bookCount) {
    int searchId;
    printf("\nEnter Book ID to Return: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid ID format.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            if (library[i].is_issued == 0) {
                printf("Alert: This book is already in the library inventory.\n");
                return;
            } else {
                library[i].is_issued = 0;
                printf("Success: Book \"%s\" returned safely.\n", library[i].title);
                return;
            }
        }
    }
    printf("Error: Book with ID %d not found.\n", searchId);
}