#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 20
#define TICKET_PRICE 12.0 // Price per ticket in dollars

// Structure to manage booking data
typedef struct {
    int seat_number;
    char passenger_name[50];
    int is_booked; 
} Seat;

// Function prototypes
void initialize_seats(Seat theater[], int size);
void display_seats(Seat theater[], int size);
void book_ticket(Seat theater[], int size);
void cancel_ticket(Seat theater[], int size);

int main() {
    Seat theater[TOTAL_SEATS];
    int choice;

    // Initialize all seats as available
    initialize_seats(theater, TOTAL_SEATS);

    while (1) {
        printf("\n===================================\n");
        printf("    MOVIE TICKET BOOKING SYSTEM    \n");
        printf("===================================\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                display_seats(theater, TOTAL_SEATS);
                break;
            case 2:
                book_ticket(theater, TOTAL_SEATS);
                break;
            case 3:
                cancel_ticket(theater, TOTAL_SEATS);
                break;
            case 4:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    return 0;
}

// Set up default values for the theater matrix
void initialize_seats(Seat theater[], int size) {
    for (int i = 0; i < size; i++) {
        theater[i].seat_number = i + 1;
        theater[i].is_booked = 0;
        strcpy(theater[i].passenger_name, "None");
    }
}

// Display visual matrix of available and taken seats
void display_seats(Seat theater[], int size) {
    printf("\n--- Theater Seating Layout ---\n");
    for (int i = 0; i < size; i++) {
        if (theater[i].is_booked) {
            printf("[ X : Seat %02d (Booked) ]  ", theater[i].seat_number);
        } else {
            printf("[ O : Seat %02d (Avail)  ]  ", theater[i].seat_number);
        }
        // Print 4 seats per row for cleaner visualization
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
}

// Process a seat reservation
void book_ticket(Seat theater[], int size) {
    int seat_num;
    printf("\nEnter seat number to book (1-%d): ", size);
    scanf("%d", &seat_num);

    // Validate if the seat exists
    if (seat_num < 1 || seat_num > size) {
        printf("Error: Invalid seat number!\n");
        return;
    }

    // Check availability 
    int index = seat_num - 1;
    if (theater[index].is_booked) {
        printf("Error: Seat %d is already booked by %s!\n", seat_num, theater[index].passenger_name);
    } else {
        printf("Enter passenger name: ");
        while (getchar() != '\n'); // Clear trailing newlines
        fgets(theater[index].passenger_name, sizeof(theater[index].passenger_name), stdin);
        
        // Remove trailing newline character from fgets
        theater[index].passenger_name[strcspn(theater[index].passenger_name, "\n")] = '\0';
        
        theater[index].is_booked = 1;
        printf("\nSuccess: Ticket booked successfully for %s!\n", theater[index].passenger_name);
        printf("Total amount due: $%.2f\n", TICKET_PRICE);
    }
}

// Void an existing reservation
void cancel_ticket(Seat theater[], int size) {
    int seat_num;
    printf("\nEnter seat number to cancel (1-%d): ", size);
    scanf("%d", &seat_num);

    if (seat_num < 1 || seat_num > size) {
        printf("Error: Invalid seat number!\n");
        return;
    }

    int index = seat_num - 1;
    if (!theater[index].is_booked) {
        printf("Error: Seat %d is already empty.\n", seat_num);
    } else {
        printf("Success: Booking for %s (Seat %d) has been canceled.\n", theater[index].passenger_name, seat_num);
        theater[index].is_booked = 0;
        strcpy(theater[index].passenger_name, "None");
    }
}