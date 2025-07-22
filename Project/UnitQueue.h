#pragma once
#ifndef UnitQueue_HEADER
#define UnitQueue_HEADER

#include "3-Queues/LinkedQueue.h" // Assuming you have included the LinkedQueue class


class unit;

class UnitQueue {
private:
    LinkedQueue<unit*> queue; // Queue of pointers to Unit objects
    int count;
public:
    // Constructor
    UnitQueue();

    // Destructor
    ~UnitQueue();
    int getCount();

    // Method to check if the queue is empty
    bool isEmpty() const;

    // Method to add a Unit object to the queue
    void enqueue(unit* u);

    // Method to remove and return the front Unit object from the queue
    unit* dequeue();

    // Method to get the front Unit object without removing it from the queue
    unit* peek() const;

   
};

#endif

