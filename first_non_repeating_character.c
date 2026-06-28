#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 // Total number of ASCII characters

// Function to find the first non-repeating character
char findFirstNonRepeating(char *str) {
    int frequency[MAX_CHAR] = {0}; // Initialize count array with 0
    
    // Step 1: Count the frequency of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        frequency[(unsigned char)str[i]]++;
    }
    
    // Step 2: Scan the string again to find the first character with a count of 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (frequency[(unsigned char)str[i]] == 1) {
            return str[i]; // Return the first unique character found
        }
    }
    
    return '\0'; // Return null character if all characters repeat
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    // Reads input string, including spaces, up to 99 characters
    scanf("%99[^\n]", str); 
    
    char result = findFirstNonRepeating(str);
    
    if (result != '\0') {
        printf("The first non-repeating character is: '%c'\n", result);
    } else {
        printf("All characters are repeating or the string is empty.\n");
    }
    
    return 0;
}