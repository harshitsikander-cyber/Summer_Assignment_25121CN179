#include <stdio.h>

int main() {
    char str[100];
    
    printf("Enter a lowercase string: ");
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Uppercase ASCII starts 32 places before lowercase
        }
    }
    
    printf("Uppercase string: %s\n", str);
    return 0;
}