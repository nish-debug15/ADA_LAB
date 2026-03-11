#include <stdio.h>

int partition(int A[], int start, int end) {
    int pivot = A[end];
    int i = start - 1, j, temp;

    for(j = start; j <= end - 1; j++) {
        if(A[j] <= pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = temp;

    return (i + 1);
}

void QuickSort(int A[], int start, int end) {
    int p;

    if(start < end) {
        p = partition(A, start, end);

        QuickSort(A, start, p - 1);
        QuickSort(A, p + 1, end);
    }
}

int main() {
    int A[20], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    QuickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
