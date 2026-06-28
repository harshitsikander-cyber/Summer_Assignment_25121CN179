#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if s2 is a rotation of s1
bool areRotations(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // If lengths are not equal, they cannot be rotations of each other
    if (len1 != len2) {
        return false;
    }

    // Allocate memory for the concatenated string (len1 * 2 + 1 for null terminator)
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Copy s1 into temp and concatenate s1 again to create s1 + s1
    strcpy(temp, s1);
    strcat(temp, s1);

    // Check if s2 is a substring of the concatenated string
    // strstr returns a pointer if found, or NULL if not found
    bool result = (strstr(temp, s2) != NULL);

    // Free dynamically allocated memory to avoid memory leaks
    free(temp);

    return result;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    if (areRotations(str1, str2)) {
        printf("Yes, '%s' is a rotation of '%s'\n", str2, str1);
    } else {
        printf("No, '%s' is not a rotation of '%s'\n", str2, str1);
    }

    return 0;
}