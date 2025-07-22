#pragma once
#include<iostream>
#include "5-PriorityQueue/priQueue.h" // Assuming you have included the LinkedQueue class


class Earth_Gunnery;

using namespace std;
//
//class Earth_Gunnery_PQueue
//{
//    priNode<Earth_Gunnery*>* head;
//    int count;
//public:
//    Earth_Gunnery_PQueue() : head(nullptr) { count = 0; }
//
//    ~Earth_Gunnery_PQueue() {
//        Earth_Gunnery* tmp;
//        int p;
//        while (dequeue(tmp, p));
//        count = 0;
//    }
//
//    void enqueue(Earth_Gunnery* data, int &priority) {
//        priority = data->getHP_comb();
//        priNode<Earth_Gunnery*>* newNode = new priNode<Earth_Gunnery*>(data, priority);
//        count++;
//        if (head == nullptr || priority > head->getPri()) {
//            newNode->setNext(head);
//            head = newNode;
//            return;
//        }
//
//        priNode<Earth_Gunnery*>* current = head;
//        while (current->getNext() && priority <= current->getNext()->getPri()) {
//            current = current->getNext();
//        }
//        newNode->setNext(current->getNext());
//        current->setNext(newNode);
//       
//    }
//
//    bool dequeue(Earth_Gunnery*& topEntry, int& pri) {
//        if (isEmpty())
//            return false;
//
//        topEntry = head->getItem(pri);
//        priNode<Earth_Gunnery*>* temp = head;
//        head = head->getNext();
//      
//        delete temp;
//        count--;
//        return true;
//    }
//
//    bool peek(Earth_Gunnery*& topEntry, int& pri) {
//        if (isEmpty())
//            return false;
//
//        topEntry = head->getItem(pri);
//        pri = head->getPri();
//        return true;
//    }
//    void print() const {
//        if (isEmpty()) {
//            std::cout << "Queue is empty." << std::endl;
//            return;
//        }
//
//        priNode<Earth_Gunnery*>* current = head;
//        std::cout << "Priority Queue Contents: [ ";
//
//        // Create a temporary queue to preserve the original order
//        Earth_Gunnery_PQueue tempQueue(*this);
//
//        while (!tempQueue.isEmpty()) {
//            int priority;
//            Earth_Gunnery* itemPtr;
//            tempQueue.dequeue(itemPtr, priority);
//            std::cout << itemPtr->getID() << "(" << priority << "), ";
//
//            // Enqueue the item back to the main queue
//           queueenqueue(itemPtr, priority);
//        }
//
//        std::cout << "]" << std::endl;
//    }
//
//
//
//
//
//    //void print()
//    //{
//    //    std::cout << "EG  " << count << "    " << "[ ";
//
//    //    // Create a temporary pointer to iterate through the priority queue
//    //    Earth_Gunnery* temp;
//
//    //    // Create a copy of the original priority queue to preserve the order
//    //    Earth_Gunnery_PQueue tempQueue = *this;
//
//    //    // Print each element in the priority queue
//    //    while (!tempQueue.isEmpty()) {
//    //        int pri;
//    //        tempQueue.dequeue(temp,pri);
//    //        std::cout << temp->getID() << ", ";
//    //    }
//
//    //    std::cout << "]" << "\n";
//    //}
//    bool isEmpty() const {
//        return head == nullptr;
//    }
//};


class Earth_Gunnery_PQueue {
private:
    priQueue<Earth_Gunnery*> queue; // Priority queue of pointers to Earth_Gunnery objects
    int count;
public:
    // Constructor
    Earth_Gunnery_PQueue();

    // Destructor
    ~Earth_Gunnery_PQueue();

    // Method to check if the priority queue is empty
    bool isEmpty() const;

    // Method to add an Earth_Gunnery object to the priority queue with a given priority
    void enqueue(Earth_Gunnery* data, int priority);

    // Method to remove and return the front Earth_Gunnery object from the priority queue
    Earth_Gunnery* dequeue();

    // Method to get the front Earth_Gunnery object without removing it from the priority queue
  /*  bool peek(Earth_Gunnery*& topEntry, int& priority) {
        return queue.peek(topEntry, priority);
    }*/

    // Method to print the priority queue contents
    void print();

    int getCount();
};
