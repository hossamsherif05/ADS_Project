
// Simple queue of integers
// We will use this in BFS (shortest path search)
// We don't use STL here (no std::queue)


#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

class Queue {
private:
    static const int capacity = 101; // max number of items we can store
    int data[capacity];              // the array that holds the values
    int frontIndex;                  // index of the first element (front of queue)
    int rearIndex;                   // index of the last element (back of queue)
    int count;                       // how many elements are in the queue now

public:
    // constructor: sets everything to empty
    Queue();

    // returns true if queue has no elements
    bool isEmpty() const;

    // returns true if queue is full (can't add more)
    bool isFull() const;

    // put a value at the back of the queue
    void enqueue(int value);

    // take out and return the value at the front of the queue
    // returns -1 if queue is empty
    int dequeue();

    // just look at the first element without removing it
    // returns -1 if queue is empty
    int front() const;

    // returns how many items are inside the queue
    int size() const;
};

#endif
