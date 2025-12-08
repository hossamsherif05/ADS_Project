#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

class Dijkstra {
private:
    const Graph &g;

public:
    Dijkstra(const Graph &graph);

    // Returns path length, fills path[] with nodes from start -> end
    // Returns 0 if no path
    int shortestPath(int start, int end, int path[], int maxPathSize);
};

#endif
