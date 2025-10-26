#include "queue.h"

Queue::Queue() {
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

bool Queue::isEmpty() const {
    return (count == 0);
}

bool Queue::isFull() const {
    return (count == MAX_SIZE);
}

void Queue::enqueue(int value) {
    if (isFull()) {
        // queue is full, ignore the enqueue
        return;
    }
    // move rear forward in circular way
    rearIndex = (rearIndex + 1) % MAX_SIZE;
    data[rearIndex] = value;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        // nothing to remove
        return -1;
    }
    int value = data[frontIndex];
    // move front forward in circular way
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
    return value;
}

int Queue::front() const {
    if (isEmpty()) {
        return -1;
    }
    return data[frontIndex];
}

int Queue::size() const {
    return count;
}
