#include "UnitQueue.h"
#include "unit.h"

UnitQueue::UnitQueue()
{
    count = 0;
}

UnitQueue::~UnitQueue()
{
    // Deallocate memory of all Unit objects in the queue
    unit* temp;
    while (!queue.isEmpty()) {
        queue.dequeue(temp);
        delete temp;
    }
    count = 0;
}

int UnitQueue::getCount()
{
    return count;
}

bool UnitQueue::isEmpty() const
{
    return queue.isEmpty();
}

void UnitQueue::enqueue(unit* u)
{
    queue.enqueue(u);
    count++;
}

unit* UnitQueue::dequeue()
{
    unit* u = nullptr;
    queue.dequeue(u);
    count--;
    return u;
}

unit* UnitQueue::peek() const
{
    unit* u = nullptr;
    queue.peek(u);
    return u;
}





