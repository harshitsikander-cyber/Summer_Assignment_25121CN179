#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

// Structure to define an inventory item
typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

// Global variables for managing the database array
Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void displayInventory();
void searchItem();
void updateStock();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n===================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM    \n");
        printf("===================================\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Stock Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add a new item to the inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Error: Inventory capacity reached!\n");
        return;
    }

    Item newItem;
    printf("\nEnter Item ID (Integer): ");
    scanf("%d", &newItem.id);
    
    // Check if ID already exists
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: An item with ID %d already exists!\n", newItem.id);
            return;
        }
    }

    clearBuffer(); // Clean input buffer before taking a string
    printf("Enter Item Name: ");
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;
    printf("Success: Item added successfully!\n");
}

// Function to print all items in the inventory
void displayInventory() {
    if (itemCount == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Quantity", "Price ($)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-12d %-10.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

// Function to search for a specific item using its ID
void searchItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty. Nothing to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

// Function to adjust the stock level of an existing item
void updateStock() {
    if (itemCount == 0) {
        printf("\nInventory is empty. Nothing to update.\n");
        return;
    }

    int updateId, newQty;
    printf("\nEnter Item ID to update stock: ");
    scanf("%d", &updateId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Current Quantity for %s is %d.\n", inventory[i].name, inventory[i].quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &newQty);
            
            if (newQty < 0) {
                printf("Error: Quantity cannot be negative.\n");
                return;
            }
            
            inventory[i].quantity = newQty;
            printf("Success: Stock updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", updateId);
}

// Utility function to clear the standard input stream buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}