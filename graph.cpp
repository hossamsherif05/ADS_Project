#include<iostream>
#include "graph.h"
using namespace std;

Graph::Graph()
{
    size=100;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            node[i][j] = 0;
        }
    }
}
void Graph::addEdge(int start, int end) {
    if (start >= 1 && start <= size && end >= 1 && end <= size)
    {
        node[start][end] = 1;
    }
}
int Graph::isEdge(int start, int end)
{
    if (start >= 1 && end <= size && start >= 1 && end <= size)
    {
        return node[start][end];
    }
    return 0;
}
void Graph::printNeighbors(int tile)
{
    if (tile < 1 || tile > size) return;
    for (int i = 1; i <= size; i++)
    {
        if (node[tile][i] == 1)
        {
            cout << i << " ";
        }
    }
}
int Graph::getSize()
{
    return size;
}
