#include <stdio.h>
#include <ctype.h> // Required for isspace()

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; // State flag: 1 if inside a word, 0 if whitespace

    while (*str) {
        // isspace() checks for ' ', '\t', '\n', '\v', '\f', '\r'
        if (isspace((unsigned char)*str)) {
            in_word = 0; 
        } 
        // If it's a non-space character and we weren't inside a word, 
        // it marks the beginning of a new word.
        else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++; // Move to the next character
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    // fgets safely reads the entire line, including spaces
    if (fgets(sentence, sizeof(sentence), stdin)) {
        int words = count_words(sentence);
        printf("Total number of words: %d\n", words);
    }

    return 0;
}