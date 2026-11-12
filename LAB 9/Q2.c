#include <stdio.h>
#include <string.h>

int main() {
    char names_arr[10][50];
    char temp_box[50];
    
    printf("Enter 10 student names:\n");
    for (int a = 0; a < 10; a++) {
        printf("Student %d: ", a + 1);
        scanf("%s", names_arr[a]);
    }
    
    // Sorting alphabetically using strcmp and swapping via strcpy
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9 - a; b++) {
            if (strcmp(names_arr[b], names_arr[b + 1]) > 0) {
                strcpy(temp_box, names_arr[b]);
                strcpy(names_arr[b], names_arr[b + 1]);
                strcpy(names_arr[b + 1], temp_box);
            }
        }
    }
    
    printf("\n--- Alphabetically Sorted Student List ---\n");
    for (int a = 0; a < 10; a++) {
        printf("%d. %s\n", a + 1, names_arr[a]);
    }

    return 0;
}