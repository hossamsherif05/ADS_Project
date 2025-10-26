//
// Simple integer queue for BFS in Snakes & Ladders
// Array-based circular queue with fixed capacity.
// No STL used.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

class Queue {
private:
    static const int MAX_SIZE = 200;
    int data[MAX_SIZE];              // storage
    int frontIndex;
    int rearIndex;
    int count;

public:

    Queue();

    bool isEmpty() const;

    bool isFull() const;


    void enqueue(int value);


    int dequeue();


    int front() const;

    int size() const;
};

#endif // UNTITLED_QUEUE_H
