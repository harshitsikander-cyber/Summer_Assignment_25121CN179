#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0}; // Initialize all character counts to 0
    int i;

    printf("Enter a string: ");
    // Safely read a line of text including spaces
    fgets(str, sizeof(str), stdin);

    // Loop through the string until the null-terminator is reached
    for (i = 0; str[i] != '\0'; i++) {
        // Exclude the trailing newline character added by fgets
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
    }

    // Print the results for characters that appeared at least once
    printf("\nCharacter Frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}