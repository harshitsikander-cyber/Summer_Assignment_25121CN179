#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 1000

int main() {
    char sentence[MAX_LIMIT];
    char longest_word[MAX_LIMIT] = "";
    int max_len = 0;
    
    printf("Enter a sentence: ");
    // Safely read the entire line including spaces
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    int i = 0;
    int len = strlen(sentence);

    // Loop through each character of the string
    while (i < len) {
        // 1. Skip any leading non-word characters (spaces, punctuation)
        while (i < len && !isalnum((unsigned char)sentence[i])) {
            i++;
        }

        // Keep track of where the current word starts
        int start_index = i;

        // 2. Scan through the characters of the current word
        while (i < len && isalnum((unsigned char)sentence[i])) {
            i++;
        }

        // Calculate the length of the current word
        int current_len = i - start_index;

        // 3. If this word is longer than the previous maximum, save it
        if (current_len > max_len) {
            max_len = current_len;
            // Copy the word into our longest_word buffer
            strncpy(longest_word, &sentence[start_index], current_len);
            longest_word[current_len] = '\0'; // Manually null-terminate
        }
    }

    // Print the final result
    if (max_len > 0) {
        printf("The longest word is: \"%s\"\n", longest_word);
        printf("Length: %d characters\n", max_len);
    } else {
        printf("No valid words found.\n");
    }

    return 0;
}