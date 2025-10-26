#include "queue.h"

using namespace std;

#include <iostream>
#include <ostream>

Queue::Queue()
{
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
    if (isFull())
    {
   cout << "Queue is full" << endl;

        return;
    }
    rearIndex = (rearIndex + 1) % MAX_SIZE;
    data[rearIndex] = value;
    count++;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    int value = data[frontIndex];
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
    return value;
}

int Queue::front() const
{
    if (isEmpty())
    {
        return -1;
    }
    return data[frontIndex];
}


int Queue::size() const
{
    return count;
}
