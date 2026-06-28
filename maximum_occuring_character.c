#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

// Function to find the maximum occurring character
char getMaxOccurringChar(char* str, int* maxCount) {
    // Create an array to keep the count of individual characters 
    int count[ASCII_SIZE] = {0};

    // Construct character count array from the input string
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // Skip newline character if it gets registered by fgets
        if (str[i] == '\n') continue; 
        
        count[(unsigned char)str[i]]++;
    }

    int max = -1;  // Initialize max count
    char result;   // Initialize result

    // Traverse the string to find the maximum occurring character
    // This approach guarantees returning the first occurrence in case of a tie
    for (int i = 0; i < len; i++) {
        if (str[i] != '\n' && max < count[(unsigned char)str[i]]) {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    *maxCount = max;
    return result;
}

int main() {
    char str[100];
    int maxCount = 0;

    printf("Enter a string: ");
    // Using fgets instead of gets() for safe input reading
    fgets(str, sizeof(str), stdin); 

    char maxChar = getMaxOccurringChar(str, &maxCount);

    if (maxCount > 0) {
        printf("The maximum occurring character is '%c' and it appears %d times.\n", maxChar, maxCount);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}