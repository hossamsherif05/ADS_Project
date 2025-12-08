#include "dijkestra.h"

Dijkstra::Dijkstra(const Graph &graph) : g(graph) {}

int Dijkstra::shortestPath(int start, int end, int path[], int maxPathSize)
{
    int n = g.getSize();

    // We assume n <= 100
    int dist[101];
    int parent[101];
    bool visited[101];

    for (int i = 1; i <= n; i++) {
        dist[i] = 101;     // "infinity"
        parent[i] = -1;
        visited[i] = false;
    }

    dist[start] = 1;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int best = 101;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < best) {
                best = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        if (u == end) break;

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (g.isEdge(u, v)) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                }
            }
        }
    }

    if (dist[end] == 101)
    {
        return 0;
    }

    // Reconstruct path backward
    int temp[101];
    int len = 0;
    int v = end;

    while (v != -1 && len < maxPathSize)
    {
        temp[len++] = v;
        v = parent[v];
    }

    // Reverse into path[]
    for (int i = 0; i < len; i++) {
        path[i] = temp[len - 1 - i];
    }

    return len;
}
