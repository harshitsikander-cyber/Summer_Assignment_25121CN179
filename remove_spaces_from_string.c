#include <stdio.h>

// Function to remove all spaces from a string in-place
void removeSpaces(char *str) {
    int read_ptr = 0;
    int write_ptr = 0;

    // Traverse the string until the null terminator is reached
    while (str[read_ptr] != '\0') {
        // If the current character is not a space, copy it
        if (str[read_ptr] != ' ') {
            str[write_ptr] = str[read_ptr];
            write_ptr++;
        }
        read_ptr++;
    }
    
    // Null-terminate the modified string to mark its new end
    str[write_ptr] = '\0';
}

int main() {
    // Example test string (must be a modifiable character array, not a string literal)
    char testStr[] = "C P r o g r a m m i n g";

    printf("Original string: \"%s\"\n", testStr);

    // Call the function to remove spaces
    removeSpaces(testStr);

    printf("Processed string: \"%s\"\n", testStr);

    return 0;
}