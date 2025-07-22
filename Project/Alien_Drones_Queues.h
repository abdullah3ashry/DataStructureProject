#ifndef Alien_DroneQueue_HEADER
#define Alien_DroneQueue_HEADER

#include "3-Queues/LinkedQueue.h" // Assuming you have included the LinkedQueue class
//#include "Alien_Drone.h"

class Alien_Drone;

class Alien_DroneQueue {
private:
    LinkedQueue<Alien_Drone*> queue; // Queue of pointers to Alien_Drone objects
    int count;
public:
    // Constructor
    Alien_DroneQueue();

    // Destructor
    ~Alien_DroneQueue();

    // Method to check if the queue is empty
    bool isEmpty() const;

    // Method to add an Alien_Drone object to the queue
    void enqueue(Alien_Drone* Drone);
    void enqueueFront(Alien_Drone* Drone);

    // Method to remove and return the front Alien_Drone object from the queue
    Alien_Drone* dequeue();

    Alien_Drone* dequeueRear();


    // Method to get the front Alien_Drone object without removing it from the queue
    Alien_Drone* peek() const;

    void print();
    // Overloading the assignment operator
    Alien_DroneQueue& operator=(const Alien_DroneQueue& other);

    // Overloading the equality operator
    bool operator==(Alien_DroneQueue& other) const;

    int getcount();
};



#endif