#include "Earth_Soldier_Queue.h"
#include "Earth_Soldier.h"

Earth_SoldierQueue::Earth_SoldierQueue()
{
	count = 0;
}
Earth_SoldierQueue::~Earth_SoldierQueue()
{
    // Deallocate memory of all Earth_Soldier objects in the queue
    Earth_Soldier* temp;
    while (!queue.isEmpty()) {
        queue.dequeue(temp);
        delete temp;
    }
    count = 0;
}
bool Earth_SoldierQueue::isEmpty() const
{
    return queue.isEmpty();
}

void Earth_SoldierQueue::enqueue(Earth_Soldier* soldier)
{
    queue.enqueue(soldier);
    count++;
}

Earth_Soldier* Earth_SoldierQueue::dequeue()
{
    Earth_Soldier* soldier = nullptr;
    queue.dequeue(soldier);
    count--;
    return soldier;
   
}

Earth_Soldier* Earth_SoldierQueue::peek() const
{
    Earth_Soldier* soldier = nullptr;
    queue.peek(soldier);
    return soldier;
}

void Earth_SoldierQueue::print()
{
    cout << "ES  " << count << "    " << "[ ";

    Earth_SoldierQueue temp;
    Earth_Soldier* ES = nullptr;

    while (!queue.isEmpty())
    {
        queue.dequeue(ES);
        cout << ES->getID() << ", ";
        temp.enqueue(ES);
    }
    while (!temp.isEmpty()) {

        queue.enqueue(temp.dequeue());
    }
    cout << "]" << "\n";
    cout << endl;
}

Earth_SoldierQueue& Earth_SoldierQueue::operator=(const Earth_SoldierQueue& other)
{
    if (this != &other) {
        // Clear current queue
        Earth_Soldier* temp;
        while (!queue.isEmpty()) {
            queue.dequeue(temp);
            delete temp;
        }

        // Copy elements from other queue
        LinkedQueue<Earth_Soldier*> tempQueue = other.queue; // Assuming LinkedQueue supports copy constructor
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(temp);
            queue.enqueue(new Earth_Soldier(*temp));
        }
    }
    return *this;
}

bool Earth_SoldierQueue::operator==(Earth_SoldierQueue& other) const
{
    LinkedQueue<Earth_Soldier*> tempQueue = other.queue; // Make a copy of the other queue
    while (!queue.isEmpty() && !tempQueue.isEmpty()) {
        Earth_Soldier* soldier1, * soldier2;
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

int Earth_SoldierQueue::getCount()
{
    return count;
}


