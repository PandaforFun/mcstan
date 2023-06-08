#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 9999999

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

int minKey(int key[], bool mstSet[]) {
    int min = INF, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST() {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d -> %d \t%d\n", parent[i]+1, i+1, graph[i][parent[i]]);
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}
