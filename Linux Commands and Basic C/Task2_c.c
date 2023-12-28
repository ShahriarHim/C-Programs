#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_special_char(char c) {
    return (c == '_' || c == ',' || c == '$' || c == '#' || c == '@');
}

int main() {
    char password[100];

    printf("Enter Your Password: ");
    scanf("%s", password);

    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool character = false;

    for (int i = 0; i < strlen(password); i++) {
        char currentChar = password[i];

        if (is_lowercase(currentChar)) {
            lowercase = true;
        } else if (is_uppercase(currentChar)) {
            uppercase = true;
        } else if (is_digit(currentChar)) {
            digit = true;
        } else if (is_special_char(currentChar)) {
            character = true;
        }
    }

    if (!lowercase) {
        printf("Lowercase character missing\n");
    }
    if (!uppercase) {
        printf("Uppercase character missing\n");
    }
    if (!digit) {
        printf("Digit missing\n");
    }
    if (!character) {
        printf("Special character missing\n");
    }

    if (lowercase && uppercase && digit && character) {
        printf("OK\n");
    }

    return 0;
}
