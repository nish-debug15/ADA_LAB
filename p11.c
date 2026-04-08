#include <stdio.h>

#define INF 999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, i, j, s;
    struct Edge edges[20];
    int dist[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination weight):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    for(i = 0; i < n; i++)
        dist[i] = INF;

    dist[s] = 0;

    for(i = 1; i <= n - 1; i++) {
        for(j = 0; j < e; j++) {
            if(dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    for(j = 0; j < e; j++) {
        if(dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", s);
    for(i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
