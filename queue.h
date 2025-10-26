//
// Simple integer queue for BFS in Snakes & Ladders
// Array-based circular queue with fixed capacity.
// No STL used.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

class Queue {
private:
    static const int MAX_SIZE = 200; // capacity of queue
    int data[MAX_SIZE];              // storage
    int frontIndex;                  // index of current front element
    int rearIndex;                   // index of last element
    int count;                       // how many elements are in the queue

public:
    // constructor: creates an empty queue
    Queue();

    // returns true if queue has no elements
    bool isEmpty() const;

    // returns true if queue is full (can't enqueue more)
    bool isFull() const;

    // add value to the back of the queue
    // if full, does nothing
    void enqueue(int value);

    // remove and return the front value
    // if empty, returns -1
    int dequeue();

    // read (but don't remove) the front value
    // if empty, returns -1
    int front() const;

    // how many elements are currently stored
    int size() const;
};

#endif // UNTITLED_QUEUE_H
