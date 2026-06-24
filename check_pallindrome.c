#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left = 0;
    int right;
    int is_palindrome = 1; // 1 means True, 0 means False

    printf("Enter a string: ");
    // Read input including spaces, stopping at a newline
    scanf("%[^\n]", str);

    // Get the index of the last character
    right = strlen(str) - 1;

    // Compare characters from both ends moving inward
    while (left < right) {
        if (str[left] != str[right]) {
            is_palindrome = 0; // Mismatch found
            break;
        }
        left++;
        right--;
    }

    // Output the result
    if (is_palindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}