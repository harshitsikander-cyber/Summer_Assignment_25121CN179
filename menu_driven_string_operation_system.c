#include <stdio.h>
#include <string.h>

// Helper function to safely clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char str1[100], str2[100];
    int choice;

    do {
        // Displaying the main menu options
        printf("\n=================================");
        printf("\n   STRING OPERATIONS SYSTEM");
        printf("\n=================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Concatenate Two Strings");
        printf("\n3. Copy One String to Another");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        // Input validation for menu choice
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the second string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                // Ensure the combined string doesn't overflow str1's bounds
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string: %s\n", str1);
                } else {
                    printf("Error: Operation would cause buffer overflow.\n");
                }
                break;

            case 3:
                printf("\nEnter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);
                printf("Successfully copied!\nDestination string: %s\n", str2);
                break;

            case 4:
                printf("\nEnter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';

                int result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Both strings are identical.\n");
                } else if (result > 0) {
                    printf("The first string is lexicographically greater.\n");
                } else {
                    printf("The second string is lexicographically greater.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';

                int len = strlen(str1);
                printf("Reversed string: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}