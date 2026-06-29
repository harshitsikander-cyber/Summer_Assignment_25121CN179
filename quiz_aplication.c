#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 3

// Structure to store question details
typedef struct {
    char questionText[200];
    char options[4][100];
    char correctAnswer;
} QuizQuestion;

// Function declarations
void displayWelcomeMessage();
void runQuiz(QuizQuestion quiz[], int totalQuestions, int *score);
void displayFinalScore(int score, int totalQuestions);

int main() {
    int score = 0;

    // Initializing the questions, options, and correct answers
    QuizQuestion quiz[TOTAL_QUESTIONS] = {
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. C", "C. Java", "D. C++"},
            'B'
        },
        {
            "What is the size of an 'int' data type in a standard 32-bit C compiler?",
            {"A. 2 Bytes", "B. 4 Bytes", "C. 8 Bytes", "D. 1 Byte"},
            'B'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. volatile", "C. mutable", "D. const"},
            'D'
        }
    };

    displayWelcomeMessage();
    runQuiz(quiz, TOTAL_QUESTIONS, &score);
    displayFinalScore(score, TOTAL_QUESTIONS);

    return 0;
}

// Displays the initial game menu
void displayWelcomeMessage() {
    printf("=========================================\n");
    printf("       WELCOME TO THE C QUIZ GAME        \n");
    printf("=========================================\n");
    printf(" Instructions: Enter A, B, C, or D for   \n");
    printf(" each question. Let's begin!\n");
    printf("=========================================\n\n");
}

// Loops through questions and processes user answers
void runQuiz(QuizQuestion quiz[], int totalQuestions, int *score) {
    char userAnswer;

    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].questionText);
        
        // Print the 4 options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Get user input and validate
        printf("Your Answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);
        userAnswer = toupper(userAnswer); // Convert to uppercase for uniformity

        // Check if answer is correct
        if (userAnswer == quiz[i].correctAnswer) {
            printf("\n Correct!\n\n");
            (*score)++;
        } else {
            printf("\n Wrong! The correct answer was %c.\n\n", quiz[i].correctAnswer);
        }
        printf("-----------------------------------------\n");
    }
}

// Displays performance remarks based on final score
void displayFinalScore(int score, int totalQuestions) {
    printf("\n=========================================\n");
    printf("               QUIZ OVER!                \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    
    if (score == totalQuestions) {
        printf("Performance: Excellent! Perfect score!\n");
    } else if (score >= totalQuestions / 2) {
        printf("Performance: Good job!\n");
    } else {
        printf("Performance: Better luck next time!\n");
    }
    printf("=========================================\n");
}