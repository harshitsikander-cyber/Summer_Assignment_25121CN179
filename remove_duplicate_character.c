#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    // Array to track ASCII characters (initialized to 0)
    int seen[256] = {0}; 
    
    int readIndex = 0;
    int writeIndex = 0;
    
    // Loop through the string until the null terminator
    while (str[readIndex] != '\0') {
        unsigned char currentChar = str[readIndex];
        
        // If the character has not been seen before
        if (seen[currentChar] == 0) {
            seen[currentChar] = 1;          // Mark as seen
            str[writeIndex] = str[readIndex]; // Write to unique position
            writeIndex++;
        }
        readIndex++;
    }
    
    // Add the null terminator to terminate the modified string
    str[writeIndex] = '\0'; 
}

int main() {
    // Example string with duplicates
    char str[] = "programming"; 
    
    printf("Original String: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}