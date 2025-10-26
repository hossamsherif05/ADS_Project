# ADS_Project

Team Members :

Habiba Khashaba 
Ahmed Medany
Hossam Sherif
Ali Alkholy
Hassan Rashwan 

Project Description:
This project models the Snakes and Ladders board using data structures.
Each square on the board (1 to 100) is a node
- Moves (dice rolls, snakes, ladders) are edges between nodes
- We plan to use BFS to find the minimum number of dice throws to reach square 100


 Main Components:
 
 Graph
- Stores connections between board squares
- Uses an adjacency matrix
- addEdge(start, end) creates a move from one square to another

Queue
- Custom queue (no STL)
- Will be used in BFS to explore the board level by level
- Supports:
  - enqueue
  - dequeue
  - front
  - isEmpty

main.cpp
- Builds the board
- Sets up snakes and ladders
- Fills the graph with all valid moves from each square (1 to 6 dice roll ahead)
