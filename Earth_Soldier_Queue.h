#ifndef Earth_SoldierQueue_HEADER
#define Earth_SoldierQueue_HEADER

#include "3-Queues/LinkedQueue.h" // Assuming you have included the LinkedQueue class


class Earth_Soldier;

class Earth_SoldierQueue {
private:
    LinkedQueue<Earth_Soldier*> queue; // Queue of pointers to Earth_Soldier objects
    int count;
public:
    // Constructor
    Earth_SoldierQueue();

    // Destructor
    ~Earth_SoldierQueue();

    // Method to check if the queue is empty
    bool isEmpty() const;

    // Method to add an Earth_Soldier object to the queue
    void enqueue(Earth_Soldier* soldier);

    // Method to remove and return the front Earth_Soldier object from the queue
    Earth_Soldier* dequeue();

    // Method to get the front Earth_Soldier object without removing it from the queue
    Earth_Soldier* peek() const;
    void print();

    // Overloading the assignment operator
    Earth_SoldierQueue& operator=(const Earth_SoldierQueue& other);

    // Overloading the equality operator
    bool operator==(Earth_SoldierQueue& other) const;

    int getCount();
};



#endif