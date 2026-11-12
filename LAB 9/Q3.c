#include <stdio.h>
#include <string.h>

int main() {
    char email_input[100];
    char domain_result[100];
    
    printf("Enter employee email address (e.g., user@rehbartech.com): ");
    scanf("%s", email_input);
    
    // Find '@' character using strchr
    char *at_symbol = strchr(email_input, '@');
    
    if (at_symbol != NULL) {
        // Move pointer past '@' to get the domain part
        char *domain_start = at_symbol + 1;
        
        // Copy domain into result variable using strcpy
        strcpy(domain_result, domain_start);
        
        printf("\nExtracted Domain: %s\n", domain_result);
    } else {
        printf("\nInvalid email address format (missing '@').\n");
    }

    return 0;
}