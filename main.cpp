#include <iostream>
#include "graph.h"
using namespace std;


using namespace std;
const int cap = 100;

void buildBoardGraph(Graph &g, int jump[], int size) {

    for (int i = 1; i <= size; i++) {
        for (int d = 1; d <= 6; d++) {
            int next = i + d;
            if (next > size) continue;
            int Pos = jump[next];
            g.addEdge(i, Pos);
        }
    }
}
int main()
{
    Graph g;

    int jump[cap + 1];
    for (int i = 1; i <= cap; i++)
    {
        jump[i] = i;
    }
    jump[6]  = 21;  //ladders
    jump[31]  = 80;
    jump[51] = 69;


    jump[24] = 4;   // snakes
    jump[37] = 14;
    jump[77] = 28;

    buildBoardGraph(g, jump, cap);

    cout << "Neighbors from 45 ";
    g.printNeighbors(45);
    cout << "Neighbors from 6: ";
    g.printNeighbors(6);
    cout << "Neighbors from 37 ";
    g.printNeighbors(37);
}