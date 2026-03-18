#include <stdio.h>

#define INF 999
int main() {
    int n, i, j;
    int cost[10][10], visited[10];
    int min, u, v, edges = 0;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i] == 1) {
                for(j = 0; j < n; j++) {
                    if(visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}
