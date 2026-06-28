#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

// Function to find the first repeating character
char findFirstRepeating(char str[]) {
    int count[MAX_CHAR] = {0};
    int len = strlen(str);

    // Step 1: Count occurrences of each character
    for (int i = 0; i < len; i++) {
        // Cast to unsigned char to handle extended ASCII safely
        count[(unsigned char)str[i]]++; 
    }

    // Step 2: Traverse string again to find the first character with a count > 1
    for (int i = 0; i < len; i++) {
        if (count[(unsigned char)str[i]] > 1) {
            return str[i];
        }
    }

    // Return null character if no repeating character is found
    return '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    // Reads input string including spaces until newline
    scanf("%[^\n]s", str); 

    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: '%c'\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}