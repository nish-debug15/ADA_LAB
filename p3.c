#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[50];
    int i, j, n, m, found = 0;

    printf("Enter the text: ");
    scanf(" %[^\n]", text);

    printf("Enter the pattern: ");
    scanf(" %[^\n]", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {    
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            printf("Pattern found at position %d\n", i + 1);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Pattern not found");
    }

    return 0;
}
