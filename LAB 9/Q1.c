#include <stdio.h>
#include <string.h>

int main() {
    char review_text[300];
    char modified_text[400];
    
    printf("Enter customer feedback message: ");
    fgets(review_text, sizeof(review_text), stdin);
    
    // Remove trailing newline if present from fgets
    review_text[strcspn(review_text, "\n")] = '\0';
    
    // 1. Count total characters using strlen
    int total_chars = strlen(review_text);
    printf("\nTotal characters in message: %d\n", total_chars);
    
    // 2. Find if "bad" or "good" exists using strstr
    char *found_bad = strstr(review_text, "bad");
    char *found_good = strstr(review_text, "good");
    
    if (found_bad != NULL) {
        printf("The word \"bad\" exists in the review.\n");
    } else {
        printf("The word \"bad\" does NOT exist in the review.\n");
    }
    
    if (found_good != NULL) {
        printf("The word \"good\" exists in the review.\n");
    } else {
        printf("The word \"good\" does NOT exist in the review.\n");
    }
    
    // 3. Replace "bad" with "not good" using strcpy and strcat logic
    if (found_bad != NULL) {
        // Calculate index where "bad" starts
        int index = found_bad - review_text;
        
        // Copy portion before "bad"
        strncpy(modified_text, review_text, index);
        modified_text[index] = '\0';
        
        // Append "not good"
        strcat(modified_text, "not good");
        
        // Append the rest of the original string after "bad" (skip 3 chars for "bad")
        strcat(modified_text, found_bad + 3);
        
        printf("\nUpdated Review (Replaced 'bad'):\n%s\n", modified_text);
    } else {
        printf("\nNo \"bad\" word found to replace. Original review:\n%s\n", review_text);
    }

    return 0;
}