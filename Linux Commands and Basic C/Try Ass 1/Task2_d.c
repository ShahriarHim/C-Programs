#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isEmailUpdated(const char* email) {

    const char* newDomain = "sheba.xyz";
    int emailLength = strlen(email);
    int domainLength = strlen(newDomain);

    if (emailLength < domainLength) {
        return false;
    }

    const char* emailDomain = email + (emailLength - domainLength);

    return strcmp(emailDomain, newDomain) == 0;
}

int main() {
    char email[100];
    
    printf("Enter the employee's email address: ");
    scanf("%s", email);
    
    if (isEmailUpdated(email)) {
        printf("Email address is okay\n");
    } else {
        printf("Email address is outdated\n");
    }
    
    return 0;
}
