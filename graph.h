#ifndef SNAKES_AND_LADDERS_GRAPH_H
#define SNAKES_AND_LADDERS_GRAPH_H

class Graph {
public:
    static const int MAX = 101; // we support tiles 1..100

private:
    int node[MAX][MAX]; // adjacency matrix
    int size;           // how many tiles are in the board (100)

public:
    Graph(); // constructor

    void addEdge(int start, int end);
    int isEdge(int start, int end);
    void printNeighbors(int tile);
    int getSize();
};

#endif // SNAKES_AND_LADDERS_GRAPH_H
