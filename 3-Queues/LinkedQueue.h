
/*
This is a program that implements the queue abstract data type using a linked list.
The queue is implemented as a chain of linked nodes that has two pointers, 
a frontPtr pointer for the front of the queue and a backPtr pointer for the back of the queue.
*/

/*

				The Node: item of type T and a "next" pointer
					------------- 
					| item| next | --->
					-------------
General Queue case:

                 frontPtr																backPtr
					\											   						/		
					 \											  					   /		
					------------- 	  ------------- 	  ------------- 	  ------------- 	  	  
					| item| next |--->| item| next |--->  | item| next |--->  | item| next |---> NULL
					------------- 	  ------------- 	  ------------- 	  -------------	  
		
Empty Case:

                 frontptr	 backptr
						\	 /				
						 \	/				
					---- NULL ------


Single Node Case:
                 frontPtr	 backPtr
					\		/	
					 \	   /			
					----------- 	
					|item| next| -->NULL
					-----------	

*/

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_
using namespace std;
#include <iostream>

#include "Node.h"
#include "QueueADT.h"

template <typename T>
class LinkedQueue:public QueueADT<T>
{
private :
	Node<T>* backPtr;
	Node<T>* frontPtr;
public :
	LinkedQueue();	
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool enqueueFront(const T& newEntry);
	bool dequeueRear(T& bckEntry);
	bool peek(T& frntEntry)  const;	
	~LinkedQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true ;
} // end enqueue

template <typename T>
bool LinkedQueue<T>::enqueueFront(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);

	if (isEmpty()) { // If the queue is empty, both frontPtr and backPtr point to the new node
		frontPtr = newNodePtr;
		backPtr = newNodePtr;
	}
	else { // If the queue is not empty, insert the new node before the front node
		newNodePtr->setNext(frontPtr);
		frontPtr = newNodePtr;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedQueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr ;	
		
	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}
template <typename T>
bool LinkedQueue<T>::dequeueRear(T& bckEntry)
{
	if (isEmpty())
		return false;

	if (frontPtr == backPtr) { // Only one node in the queue
		bckEntry = backPtr->getItem();
		delete backPtr;
		frontPtr = nullptr;
		backPtr = nullptr;
		return true;
	}

	// Traverse the list to find the second last node
	Node<T>* currentPtr = frontPtr;
	while (currentPtr->getNext() != backPtr) {
		currentPtr = currentPtr->getNext();
	}

	bckEntry = backPtr->getItem(); // Retrieve data from the last node
	delete backPtr; // Delete the last node
	backPtr = currentPtr; // Update backPtr to point to the second last node
	backPtr->setNext(nullptr); // Set the next pointer of the new last node to nullptr
	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool LinkedQueue<T>:: peek(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	//Note that the cout statements here is just for learning purpose
	//They should be normally removed from the destructor
	/*cout<<"\nStarting LinkedQueue destructor...";
	cout<<"\nFreeing all nodes in the queue...";*/

	//Free all nodes in the queue
	T temp;
	while(dequeue(temp));
	//
	//cout<<"\n Is LinkedQueue Empty now?? ==> "<<boolalpha<<isEmpty();
	//cout<<"\nEnding LinkedQueue destructor..."<<endl;
}

#endif