#include <stdio.h>
#include <stdlib.h>
#define V 5 // Number of vertices in the graph
#define E 7 // Number of edges in the graph
// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};
// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
// Function to find the subset of an element i (uses path compression technique)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
// Function to perform union of two subsets (uses union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    // Attach smaller rank tree under the root of the higher rank tree
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        // If ranks are the same, make one as the root and increment its rank by one
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }}
// Function to perform Kruskal's algorithm to find Minimum Spanning Tree
void kruskalMST(struct Edge edges[]) {
    struct Edge result[V]; // Array to store the MST
    int resultIndex = 0;   // Index used to store the edges in the result array
    // Step 1: Sort all the edges in non-decreasing order of their weights
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    // Create V subsets with single elements
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    // Step 2: Iterate through all sorted edges and add them to the MST
    for (int i = 0; i < E && resultIndex < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        // Include the edge only if including it doesn't create a cycle
        if (x != y) {
            result[resultIndex++] = edges[i];
            unionSets(subsets, x, y);
        } }
    // Print the MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    free(subsets);
}
int main() {
    // Example graph represented by edges
    struct Edge edges[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 3, 8},
        {1, 2, 3}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };
    // Print the Minimum Spanning Tree using Kruskal's Algorithm
    kruskalMST(edges);
    return 0;
}

