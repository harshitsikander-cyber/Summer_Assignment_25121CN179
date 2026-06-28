#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

// Function to find and print common characters
void findCommonCharacters(char str1[], char str2[]) {
    int freq1[MAX_CHAR] = {0};
    int freq2[MAX_CHAR] = {0};
    int i;

    // Count character frequencies in the first string (case-insensitive)
    for (i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            freq1[str1[i] - 'a']++;
        } else if (str1[i] >= 'A' && str1[i] <= 'Z') {
            freq1[str1[i] - 'A']++;
        }
    }

    // Count character frequencies in the second string (case-insensitive)
    for (i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            freq2[str2[i] - 'a']++;
        } else if (str2[i] >= 'A' && str2[i] <= 'Z') {
            freq2[str2[i] - 'A']++;
        }
    }

    // Print common characters
    printf("Common characters: ");
    int found = 0;
    for (i = 0; i < MAX_CHAR; i++) {
        // If a character exists in both arrays, it is common
        if (freq1[i] > 0 && freq2[i] > 0) {
            printf("%c ", i + 'a');
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100];

    // Read user inputs using fgets to allow spaces
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline characters added by fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    findCommonCharacters(str1, str2);

    return 0;
}