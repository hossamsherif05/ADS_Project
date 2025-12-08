#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

class Graph {
private:
    static const int MAX_SIZE = 100;
    int size;
    int node[MAX_SIZE + 1][MAX_SIZE + 1];

public:
    Graph();                 // default 100
    void setSize(int s);     // allow smaller boards

    void addEdge(int start, int end);
    int  isEdge(int start, int end) const;
    void printNeighbors(int tile) const;
    int  getSize() const;
};

#endif
