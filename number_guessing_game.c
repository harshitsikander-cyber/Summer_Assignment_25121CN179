#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, user_guess, total_attempts = 0;

    // Seed the random number generator using the current system time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secret_number = (rand() % 100) + 1;

    printf("=========================================\n");
    printf("   Welcome to the Number Guessing Game!  \n");
    printf("=========================================\n");
    printf("I have chosen a secret number between 1 and 100.\n\n");

    // Loop runs until the player guesses the correct number
    do {
        printf("Enter your guess: ");
        
        // Read input from the player
        if (scanf("%d", &user_guess) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            // Clear input buffer to avoid infinite loops on char input
            while (getchar() != '\n');
            continue;
        }

        total_attempts++;

        // Provide feedback based on the player's guess
        if (user_guess > secret_number) {
            printf("❌ Too High! Try a smaller number.\n\n");
        } else if (user_guess < secret_number) {
            printf("❌ Too Low! Try a larger number.\n\n");
        } else {
            printf("\n🎉 Congratulations! You guessed the right number!\n");
            printf("🏆 Total attempts made: %d\n", total_attempts);
        }

    } while (user_guess != secret_number);

    return 0;
}