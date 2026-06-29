#include <stdio.h>

int main() {
    int age;
    
    // Prompt the user to enter their age
    printf("Enter your age: ");
    scanf("%d", &age);
    
    // Check if the age meets the eligibility requirement
    if (age >= 18) {
        printf("Congratulations! You are eligible to vote.\n");
    } else if (age < 0) {
        printf("Invalid input! Please enter a valid positive age.\n");
    } else {
        printf("Sorry, you are not eligible to vote. You must be 18 or older.\n");
        printf("You can vote in %d years.\n", 18 - age);
    }
    
    return 0;
}