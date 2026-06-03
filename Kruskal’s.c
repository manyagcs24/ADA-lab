#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
};

int find(struct Subset subsets[], int i) {
    while (subsets[i].parent != i)
        i = subsets[i].parent;
    return i;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    subsets[xroot].parent = yroot;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    struct Subset subsets[V];

    qsort(edges, E, sizeof(struct Edge), compare);

    for (int i = 0; i < V; i++)
        subsets[i].parent = i;

    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in MST:\n");
    int total = 0;

    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n",
               result[i].src,
               result[i].dest,
               result[i].weight);
        total += result[i].weight;
    }

    printf("Total Cost = %d\n", total);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int E = V * (V - 1) / 2;
    struct Edge edges[E];

    printf("Enter edges (src dest weight):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    KruskalMST(edges, V, E);

    return 0;
}
