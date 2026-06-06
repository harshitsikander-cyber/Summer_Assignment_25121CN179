#include <stdio.h>



int countSetBitsKernighan(unsigned int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1); 
        count++;
    }
    return count;
}



int countSetBitsSimple(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;          
    }
    return count;
}

int main() {
    unsigned int num;

    printf("Enter an integer: ");
    if (scanf("%u", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    
    int bits = countSetBitsKernighan(num);

    printf("The number of set bits (1s) in %u is: %d\n", num, bits);

    return 0;
}