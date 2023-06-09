#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(int numVertices, int source, struct Edge* edges, int numEdges) {
    int* distance = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INFINITY;
    }
    distance[source] = 0;

    // Relax edges now one by one
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (distance[u] != INFINITY && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;

        if (distance[u] != INFINITY && distance[u] + w < distance[v]) {
            printf("Negative cycle detected.\n");
            free(distance);
            return;
        }
    }

    // Print the shortest distances from the source
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }

    free(distance);
}

int main() {
    int numVertices = 5;
    int numEdges = 8;
    struct Edge edges[] = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2}
    };
    int source = 0;

    bellmanFord(numVertices, source, edges, numEdges);

    return 0;
}
