#include <stdio.h>
#include <string.h>

// Function to search for a substring in a string
int searchSubstring(char *str, char *substr) {
    int len1 = strlen(str);
    int len2 = strlen(substr);

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len2) {
            return i; // Substring found at index i
        }
    }

    return -1; // Substring not found
}

// Function to concatenate two strings
void concatenateStrings(char *str1, char *str2, char *result) {
    strcpy(result, str1);
    strcat(result, str2);
}

// Function to extract a substring from a string
void extractSubstring(char *str, int start, int length, char *result) {
    strncpy(result, str + start, length);
    result[length] = '\0'; // Null-terminate the substring
}

int main() {
    char str1[100], str2[100], substring[100], result[200];
    
    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    printf("Enter the substring to search for: ");
    gets(substring);

    int index = searchSubstring(str1, substring);

    if (index != -1) {
        printf("'%s' found at index %d in '%s'\n", substring, index, str1);
    } else {
        printf("'%s' not found in '%s'\n", substring, str1);
    }

    concatenateStrings(str1, str2, result);
    printf("Concatenated string: %s\n", result);

    int start, length;
    printf("Enter the start index for substring extraction: ");
    scanf("%d", &start);
    printf("Enter the length of substring to extract: ");
    scanf("%d", &length);
    
    extractSubstring(str1, start, length, result);
    printf("Extracted substring: %s\n", result);

    return 0;
}

