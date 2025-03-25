#include "Alien_Drones_Queues.h"
#include "Alien_Drone.h"


Alien_DroneQueue::Alien_DroneQueue()
{
	count = 0;
}

Alien_DroneQueue::~Alien_DroneQueue()
{
    // Deallocate memory of all Alien_Drone objects in the queue
    Alien_Drone* temp;
    while (!queue.isEmpty()) {
        queue.dequeue(temp);
        delete temp;
    }
    count = 0;
}

bool Alien_DroneQueue::isEmpty() const
{
    return queue.isEmpty();
}

void Alien_DroneQueue::enqueue(Alien_Drone* Drone)
{
    queue.enqueue(Drone);
    count++;
}
void Alien_DroneQueue::enqueueFront(Alien_Drone* Drone)
{
    queue.enqueueFront(Drone);
    count++;
}

Alien_Drone* Alien_DroneQueue::dequeue()
{
    Alien_Drone* Drone = nullptr;
    queue.dequeue(Drone);
    count--;
    return Drone;
}
Alien_Drone* Alien_DroneQueue::dequeueRear()
{
    Alien_Drone* Drone = nullptr;
    queue.dequeueRear(Drone);
    count--;
    return Drone;
}

Alien_Drone* Alien_DroneQueue::peek() const
{
    Alien_Drone* Drone = nullptr;
    queue.peek(Drone);
    return Drone;
}

void Alien_DroneQueue::print()
{
    cout << "AD  " << count << "    " << "[ ";
 
    Alien_DroneQueue temp;
    Alien_Drone *AD=nullptr;
  
    while (!queue.isEmpty())
    {
        queue.dequeue(AD);
        cout << AD->getID() << ", ";
        temp.enqueue(AD);
    }
    while (!temp.isEmpty()) {
       
        queue.enqueue(temp.dequeue());
    }
    cout << "]" << "\n";
    cout << endl;
}

Alien_DroneQueue& Alien_DroneQueue::operator=(const Alien_DroneQueue& other)
{
    if (this != &other) {
        // Clear current queue
        Alien_Drone* temp;
        while (!queue.isEmpty()) {
            queue.dequeue(temp);
            delete temp;
        }

        // Copy elements from other queue
        LinkedQueue<Alien_Drone*> tempQueue = other.queue; // Assuming LinkedQueue supports copy constructor
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(temp);
            queue.enqueue(new Alien_Drone(*temp));
        }
    }
    return *this;
}

bool Alien_DroneQueue::operator==(Alien_DroneQueue& other) const
{
    LinkedQueue<Alien_Drone*> tempQueue = other.queue; // Make a copy of the other queue
    while (!queue.isEmpty() && !tempQueue.isEmpty()) {
        Alien_Drone* Drone1, * Drone2;
        queue.peek(Drone1);
        tempQueue.peek(Drone2);
        if (!(*Drone1 == *Drone2))
            return false;
        other.queue.dequeue(Drone1);
        tempQueue.dequeue(Drone2);
    }
    // If both queues are empty or if both became empty together, they are equal
    return queue.isEmpty() && tempQueue.isEmpty();
}

int Alien_DroneQueue::getcount()
{
    return count;
}
