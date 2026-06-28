#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dest) {
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (i < len) {
        // Store the current character
        dest[j++] = src[i];

        // Count consecutive occurrences of the current character
        int count = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }

        // Convert the integer count to a string and append it to dest
        // sprintf handles counts greater than 9 seamlessly
        j += sprintf(&dest[j], "%d", count);

        i++;
    }
    
    // Append the null-terminator to finish the compressed string
    dest[j] = '\0';
}

int main() {
    char source[100];
    // Allocate twice the source size to handle the worst-case scenario (e.g., "abcdef" -> "a1b1c1d1e1f1")
    char compressed[200]; 

    printf("Enter a string to compress: ");
    if (fgets(source, sizeof(source), stdin)) {
        // Remove trailing newline character from fgets if present
        source[strcspn(source, "\n")] = '\0';

        compressString(source, compressed);

        printf("Original String:   %s\n", source);
        printf("Compressed String: %s\n", compressed);
    }

    return 0;
}