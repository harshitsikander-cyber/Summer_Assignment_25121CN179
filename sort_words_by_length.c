#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

// Comparator function for qsort
int compareWords(const void *a, const void *b) {
    // Cast the void pointers to character pointers (strings)
    const char *wordA = (const char *)a;
    const char *wordB = (const char *)b;

    size_t lenA = strlen(wordA);
    size_t lenB = strlen(wordB);

    // Sort by length: smaller lengths come first
    if (lenA < lenB) return -1;
    if (lenA > lenB) return 1;

    // Optional: If lengths are equal, sort alphabetically
    return strcmp(wordA, wordB);
}

int main() {
    int n;
    char words[MAX_WORDS][MAX_LENGTH];

    // Get number of words from user
    printf("Enter the number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    // Read the words
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Sort using the standard library qsort function
    qsort(words, n, sizeof(words[0]), compareWords);

    // Display the sorted results
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}