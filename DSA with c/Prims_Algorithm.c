#include <stdio.h>
#include <limits.h>
#define V 5 // Number of vertices in the graph
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
      }}
    return min_index;}
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }}
void primMST(int graph[V][V]) {
    int parent[V]; // To store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    int mstSet[V]; // To represent the set of vertices included in the MST
 // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
// Always include the first vertex in MST.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST.
// The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1; // Include the picked vertex in the MST set
// Update key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            } } }
// Print the constructed MST
    printMST(parent, graph);
}
int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    // Print the Minimum Spanning Tree
    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph);
    return 0;}

