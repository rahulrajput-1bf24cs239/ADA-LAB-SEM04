#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure for subset (Union-Find)
struct Subset {
    int parent;
    int rank;
};

// Find function (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function (by rank)
void unionSet(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];  // store MST
    struct Subset subsets[MAX];

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0; // index for result
    int i = 0; // index for edges

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.u);
        int y = find(subsets, next.v);

        if (x != y) {
            result[e++] = next;
            unionSet(subsets, x, y);
        }
    }

    // Print MST
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].weight);
    }
}

// Driver code
int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[MAX];

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
