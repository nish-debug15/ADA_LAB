#include <stdio.h>

int main() {
    int n, i;
    int a[50];
    int key;
    int comparisons;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Best Case
    key = a[0];
    comparisons = 0;

    for(i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == key) {
            break;
        }
    }
    printf("\nBest Case (Key at first position): %d comparisons", comparisons);

    // worst case
    key = a[n - 1];
    comparisons = 0;

    for(i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == key) {
            break;
        }
    }
    printf("\nWorst Case (Key at last position): %d comparisons", comparisons);

    // unsuccessful case
    key = -1;   // assuming -1 is not in the array
    comparisons = 0;

    for(i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == key) {
            break;
        }
    }
    printf("\nUnsuccessful Case (Key not present): %d comparisons", comparisons);
      return 0;
}
