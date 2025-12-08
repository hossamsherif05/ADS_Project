#include "queue.h"
using namespace std;

#include <iostream>
#include <ostream>


Queue::Queue()
{
    frontIndex = 0;   // the front of the queue (where we remove)
    rearIndex = -1;   // the back of the queue (where we add)
    count = 0;        // how many items are in the queue right now
}

// Check if the queue is empty
bool Queue::isEmpty() const
{
    return (count == 0);
}

// Check if the queue is full (no more space)
bool Queue::isFull() const {
    return (count == capacity);
}

// Add a new number to the back of the queue
void Queue::enqueue(int value) {
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return; // do nothing if full
    }

    rearIndex = rearIndex + 1; // move rear forward
    data[rearIndex] = value;     // store the value at the new rear
    count++;                     // one more item now
}

// Remove and return the number at the front of the queue
int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1; // queue is empty, nothing to remove
    }

    int value = data[frontIndex]; // get the first element
    frontIndex = frontIndex + 1; // move the front forward
    count--;                       // one less item now

    return value; // return the removed value
}

// Look at the front of the queue without removing it
int Queue::front() const
{
    if (isEmpty())
    {
        return -1; // nothing in the queue
    }
    return data[frontIndex];
}

// Return how many items are inside the queue
int Queue::size() const
{
    return count;
}
