#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20

// Graph representation using an adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

// Function to generate a random directed graph
void generate_random_directed_graph(int V, int E) {
    int count = 0, a, b;

    while(count < E) {
        a = rand() % V;
        b = rand() % V;
        if(a != b && graph[a][b] == 0) {
            graph[a][b] = 1; // Add edge
            count++;
        }
    }
}

// DFS function to count reachable vertices
void dfs(int start_vertex, int V, int visited[], int *count) {
    visited[start_vertex] = 1;
    *count += 1;

    for(int i = 0; i < V; i++) {
        if(graph[start_vertex][i] == 1 && !visited[i]) {
            dfs(i, V, visited, count);
        }
    }
}

// Function to calculate average reachable vertices
double average_reachable_vertices(int V, int num_experiments) {
    int total_reachable = 0;

    for(int i = 0; i < num_experiments; i++) {
        int visited[MAX_VERTICES] = {0};
        int count = 0;
        int start_vertex = rand() % V;
        dfs(start_vertex, V, visited, &count);
        total_reachable += count;
    }

    return (double)total_reachable / num_experiments;
}

int main() {
    int V = 5; // Number of vertices
    int E = 7; // Number of edges
    int num_experiments = 100;
    srand(time(NULL)); // Initialize random number generator

    generate_random_directed_graph(V, E);
    double avg_reachable = average_reachable_vertices(V, num_experiments);

    printf("Average number of reachable vertices: %f\n", avg_reachable);

    return 0;
}
