#include <stdio.h>


int isPalindrome(char* string) {
    char* start = string;
    char* end = string;

    while (*end != '\0') {
        ++end;
    }
    --end;

    while (start < end) {
        if (*start != *end) {
            return 0; 
        }
        ++start;
        --end;
    }

    return 1; 
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return 0;
}
