
#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, k;
    int D[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &D[i][j]);
            if(D[i][j] == 0 && i != j)
                D[i][j] = INF;
        }
    }

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    printf("Shortest distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
