#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp, rem, digits;
    double sum;

    // Get the range from the user
    printf("Enter the starting and ending numbers of the range: ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    // Swap bounds if the user enters a larger starting number
    if (start > end) {
        temp = start;
        start = end;
        end = temp;
    }

    // Iterate through each number in the range
    for (i = start; i <= end; i++) {
        temp = i;
        digits = 0;
        sum = 0;

        // Step 1: Count the number of digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = i;

        // Step 2: Compute the sum of digits raised to the power of 'digits'
        while (temp != 0) {
            rem = temp % 10;
            // Use round() to avoid floating-point inaccuracies from pow()
            sum += round(pow(rem, digits));
            temp /= 10;
        }

        // Step 3: Check if the sum equals the original number
        if ((int)sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}