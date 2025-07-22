#include "Earth_Gunnery_PQueue.h"
#include "Earth_Gunnery.h"

Earth_Gunnery_PQueue::Earth_Gunnery_PQueue()
{
	count = 0;
}

Earth_Gunnery_PQueue::~Earth_Gunnery_PQueue()
{
}

bool Earth_Gunnery_PQueue::isEmpty() const
{
    return queue.isEmpty();
}

void Earth_Gunnery_PQueue::enqueue(Earth_Gunnery* data, int priority)
{
    queue.enqueue(data, priority);
    count++;
}

Earth_Gunnery* Earth_Gunnery_PQueue::dequeue()
{
    Earth_Gunnery* EG = nullptr;
    int pri;


    queue.dequeue(EG, pri);
    count--;
    return EG;
}

void Earth_Gunnery_PQueue::print()
{
    /*cout << "AD  " << count << "    " << "[ ";

    Alien_DroneQueue temp;
    Alien_Drone* AD = nullptr;

    while (!queue.isEmpty())
    {
        queue.dequeue(AD);
        cout << AD->getID() << ",";
        temp.enqueue(AD);
    }
    while (!temp.isEmpty()) {

        queue.enqueue(temp.dequeue());
    }
    cout << "]" << "\n";*/
    //if (isEmpty()) {
    //    std::cout << "Priority queue is empty." << std::endl;
    //    return;
    //}

    cout << "EG  " << count << "    " << "[ ";

    Earth_Gunnery_PQueue tempQueue;

    Earth_Gunnery* item;
    int priority;
    while (!queue.isEmpty()) {

        queue.dequeue(item, priority);
        cout << item->getID() << ", ";
        tempQueue.enqueue(item, priority);
    }
    while (!tempQueue.isEmpty())
    {
        item = tempQueue.dequeue();
        queue.enqueue(item, priority);
    }
    std::cout << "]" << std::endl;
    cout << endl;
}

int Earth_Gunnery_PQueue::getCount()
{
    return count;
}
