#include<stdio.h>
#define V 4

int tsp(int graph[][V], int visited[], int pos, int n, int count, int cost, int ans) {
    if (count == n && graph[pos][0]) {
        ans = ans < cost + graph[pos][0] ? ans : cost + graph[pos][0];
        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            ans = tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], ans);
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    visited[0] = 1;
    int ans = tsp(graph, visited, 0, V, 1, 0, INT_MAX);
    printf("Minimum cost: %d\n", ans);

    return 0;
}
