#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "graph.h"
#include "dijkestra.h"

using namespace std;

const int MAX_TILES = 100;

// Build edges based on dice + jump
void buildBoardGraph(Graph &g, int jump[], int size) {
    for (int i = 1; i <= size; i++) {
        for (int d = 1; d <= 6; d++) {
            int next = i + d;
            if (next > size) continue;

            int finalPos = jump[next];
            g.addEdge(i, finalPos);
        }
    }
}


using namespace std;

int chooseBoardDim()
{
    int choice;

    while (true)
    {
        cout << "Choose board size:\n";
        cout << "1) 5 x 5  (25 tiles)\n";
        cout << "2) 8 x 8  (64 tiles)\n";
        cout << "3) 10 x 10 (100 tiles)\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: return 5;
            case 2: return 8;
            case 3: return 10;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n\n";
                break;
        }

        }
    }



void Jumps(int jump[], int tiles)
{
    for (int i = 1; i <= tiles; i++) jump[i] = i;

    if (tiles == 25)
    {
        // Ladders
        jump[3]  = 11;
        jump[6]  = 14;
        jump[9]  = 18;

        // Snakes
        jump[16] = 8;
        jump[21] = 13;
        jump[24] = 15;

        return;
    }


    if (tiles == 64)
    {
        // Ladders
        jump[4]  = 16;
        jump[9]  = 31;
        jump[20] = 38;
        jump[28] = 50;
        jump[40] = 59;

        // Snakes
        jump[18] = 7;
        jump[35] = 22;
        jump[47] = 26;
        jump[53] = 41;
        jump[62] = 45;

        return;
    }


    // Ladders
    if (tiles >= 38) jump[4]  = 14;
    if (tiles >= 100) jump[9]  = 31;
    if (tiles >= 22) jump[20] = 38;
    if (tiles >= 84) jump[28] = 84;
    if (tiles >= 68) jump[40] = 59;
    if (tiles >= 91) jump[63] = 81;
    if (tiles >= 100) jump[71] = 91;

    // Snakes
    if (tiles >= 17) jump[17] = 7;
    if (tiles >= 54) jump[54] = 34;
    if (tiles >= 62) jump[62] = 19;
    if (tiles >= 87) jump[87] = 36;
    if (tiles >= 95) jump[95] = 75;
    if (tiles >= 99) jump[99] = 78;
}


// Simple dice
int rollDice()
{
    return (rand() % 6) + 1;
}

// Prints live shortest-path hint from current position
void printLiveHint(Dijkstra &dj, int playerPos, int tiles)
{

    int path[MAX_TILES + 1];
    int len = dj.shortestPath(playerPos, tiles, path, tiles + 1);

    if (len == 0) {
        cout << "Hint: no path found (check board setup).\n";
        return;
    }

    cout << "Hint shortest path from " << playerPos << " to " << tiles << ":\n";
    for (int i = 0; i < len; i++) {
        cout << path[i] << " ";
    }
    cout << "\nMinimum remaining moves (best-case) = " << (len - 1) << "\n";
}


int main()
{
    srand((unsigned)time(nullptr));


    int dim = chooseBoardDim();
    int tiles = dim * dim;

    if (tiles > MAX_TILES) tiles = MAX_TILES;


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 2) setup graph + jumps
    Graph g;
    g.setSize(tiles);

    int jump[MAX_TILES + 1];
    Jumps(jump, tiles);

    buildBoardGraph(g, jump, tiles);

    Dijkstra dj(g);

    // 3) gameplay
    int playerPos = 1;

    cout << "\nGame started: " << dim << "x" << dim
         << " (" << tiles << " tiles)\n";


    printLiveHint(dj, playerPos, tiles);

    while (playerPos != tiles)
    {
        cout << "\nYou are on tile " << playerPos
             << ". Press Enter to roll the dice...";
        cin.get();

        int dice = rollDice();
        cout << "Dice = " << dice << "\n";

        int oldPos = playerPos;

        // Move only if not exceeding last tile
        if (playerPos + dice <= tiles) {
            playerPos += dice;
        } else {
            cout << "Roll exceeds final tile. Staying at " << playerPos << "\n";
        }

        int afterMove = playerPos;

        // Apply snake/ladder
        playerPos = jump[playerPos];

        if (playerPos != afterMove) {
            if (playerPos > afterMove)
                cout << "Ladder! " << afterMove << " -> " << playerPos << "\n";
            else
                cout << "Snake! " << afterMove << " -> " << playerPos << "\n";
        }

        cout << "Moved: " << oldPos << " -> " << playerPos << "\n";



        printLiveHint(dj, playerPos, tiles);
    }

    cout << "\n You reached tile " << tiles << "! You win!\n";
    return 0;
}
