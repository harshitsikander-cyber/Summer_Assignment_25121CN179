#include <stdio.h>

int main() {
    int rows = 5; // Number of lines to print

    for (int i = 1; i <= rows; i++) {
        // 1. Print leading spaces for pyramid alignment
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // 2. Print characters in ascending order (A up to the peak character)
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            printf("%c", ch);
            ch++;
        }

        // 3. Print characters in descending order (back down to A)
        ch -= 2; // Step back to the character right before the peak
        for (int j = 1; j < i; j++) {
            printf("%c", ch);
            ch--;
        }

        // 4. Move to the next line
        printf("\n");
    }

    return 0;
}