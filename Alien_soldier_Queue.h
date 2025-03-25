#ifndef Alien_SoldierQueue_HEADER
#define Alien_SoldierQueue_HEADER

#include "3-Queues/LinkedQueue.h" // Assuming you have included the LinkedQueue class


class Alien_Soldier;

class Alien_SoldierQueue {
private:
    LinkedQueue<Alien_Soldier*> queue; // Queue of pointers to Alien_Soldier objects
    int count;
public:
    // Constructor
    Alien_SoldierQueue();

    // Destructor
    ~Alien_SoldierQueue();
    int getcount();

    // Method to check if the queue is empty
    bool isEmpty() const;

    // Method to add an Alien_Soldier object to the queue
    void enqueue(Alien_Soldier* soldier);

    // Method to remove and return the front Alien_Soldier object from the queue
    Alien_Soldier* dequeue();

    // Method to get the front Alien_Soldier object without removing it from the queue
    Alien_Soldier* peek() const;

    // Overloading the assignment operator
    Alien_SoldierQueue& operator=(const Alien_SoldierQueue& other);
    void print();

    // Overloading the equality operator
    bool operator==(Alien_SoldierQueue& other) const;
};



#endif