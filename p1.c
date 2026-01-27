// A Program to Implement Linear Search on A List of Elements.
// AIM: Given a list of elements and a key element, search for the key in the list using Linear Search.

#include <stdio.h>

int main() {
    int n, i, key;
    int a[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at position %d", i + 1);
            return 0;
        }
    }

    printf("Element not found");
    return 0;
}
