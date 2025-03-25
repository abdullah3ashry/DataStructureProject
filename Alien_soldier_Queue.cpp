#include "Alien_soldier_Queue.h"
#include "Alien_Soldier.h"

Alien_SoldierQueue::Alien_SoldierQueue()
{
	count = 0;
}

Alien_SoldierQueue::~Alien_SoldierQueue()
{
    // Deallocate memory of all Alien_Soldier objects in the queue
    Alien_Soldier* temp;
    while (!queue.isEmpty()) {
        queue.dequeue(temp);
        delete temp;
    }
    count = 0;
}

int Alien_SoldierQueue::getcount()
{
    return count;
}

bool Alien_SoldierQueue::isEmpty() const
{
    return queue.isEmpty();
}

void Alien_SoldierQueue::enqueue(Alien_Soldier* soldier)
{
    queue.enqueue(soldier);
    count++;
}

Alien_Soldier* Alien_SoldierQueue::dequeue()
{
    Alien_Soldier* soldier = nullptr;
    queue.dequeue(soldier);
    count--;
    return soldier;
}

Alien_Soldier* Alien_SoldierQueue::peek() const
{
    Alien_Soldier* soldier = nullptr;
    queue.peek(soldier);
    return soldier;
}

Alien_SoldierQueue& Alien_SoldierQueue::operator=(const Alien_SoldierQueue& other)
{
    if (this != &other) {
        // Clear current queue
        Alien_Soldier* temp;
        while (!queue.isEmpty()) {
            queue.dequeue(temp);
            delete temp;
        }

        // Copy elements from other queue
        LinkedQueue<Alien_Soldier*> tempQueue = other.queue; // Assuming LinkedQueue supports copy constructor
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(temp);
            queue.enqueue(new Alien_Soldier(*temp));
        }
    }
    return *this;
}

void Alien_SoldierQueue::print()
{
    cout << "AS  " << count << "    " << "[ ";

    Alien_SoldierQueue temp;
    Alien_Soldier* AS = nullptr;

    while (!queue.isEmpty())
    {
        queue.dequeue(AS);
        cout << AS->getID() << ", ";
        temp.enqueue(AS);
    }
    while (!temp.isEmpty()) {

        queue.enqueue(temp.dequeue());
    }
    cout << "]" << "\n";
    cout << endl;
}

bool Alien_SoldierQueue::operator==(Alien_SoldierQueue& other) const
{
    LinkedQueue<Alien_Soldier*> tempQueue = other.queue; // Make a copy of the other queue
    while (!queue.isEmpty() && !tempQueue.isEmpty()) {
        Alien_Soldier* soldier1, * soldier2;
        queue.peek(soldier1);
        tempQueue.peek(soldier2);
        if (!(*soldier1 == *soldier2))
            return false;
        other.queue.dequeue(soldier1);
        tempQueue.dequeue(soldier2);
    }
    // If both queues are empty or if both became empty together, they are equal
    return queue.isEmpty() && tempQueue.isEmpty();
}

