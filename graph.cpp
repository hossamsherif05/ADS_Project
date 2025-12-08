#include "graph.h"

Graph::Graph() {
    size = MAX_SIZE;
    for (int i = 1; i <= MAX_SIZE; i++) {
        for (int j = 1; j <= MAX_SIZE; j++) {
            node[i][j] = 0;
        }
    }
}

void Graph::setSize(int s) {
    if (s < 1) s = 1;
    if (s > MAX_SIZE) s = MAX_SIZE;
    size = s;

    // Clear only relevant region (safe and simple)
    for (int i = 1; i <= MAX_SIZE; i++)
     {
        for (int j = 1; j <= MAX_SIZE; j++) {
            node[i][j] = 0;
        }
    }
}


void Graph::addEdge(int start, int end) {
    if (start < 1 || start > size) return;
    if (end < 1 || end > size) return;
    node[start][end] = 1;
}

int Graph::isEdge(int start, int end) const {
    if (start < 1 || start > size) return 0;
    if (end < 1 || end > size) return 0;
    return node[start][end];
}

void Graph::printNeighbors(int tile) const {
    if (tile < 1 || tile > size) return;

    std::cout << "Neighbors of " << tile << ": ";
    for (int j = 1; j <= size; j++) {
        if (node[tile][j]) std::cout << j << " ";
    }
    std::cout << "\n";
}

int Graph::getSize() const {
    return size;
}
