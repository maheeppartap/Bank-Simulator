/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

/* None of the current content of this file can be modified. */
/* todo: make a constructor and destructor
 * */
#pragma once

#include "Node.h"
#include "EmptyDataCollectionException.h"

template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

    Node<T>* head;      // Pointer to first node in the chain
    int elementCount;   // Current count of list items

/* You can add private methods to this class */

public:

    // Default Constructor
    PriorityQueue();

    // Copy Constructor
    PriorityQueue(const PriorityQueue& rhsPriorityQueue);

    // Destructor
    ~PriorityQueue();

    // Description: Returns the number of elements in the Priority Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const T& newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    T& peek() throw(EmptyDataCollectionException);

};

template<class T>
PriorityQueue<T>::PriorityQueue() {
    head = NULL;
    elementCount = 0;
}

template<class T>
int PriorityQueue<T>::getElementCount() const {
    return elementCount;
}

template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return head == NULL;
}

template<class T>
bool PriorityQueue<T>::enqueue(const T &newElement) {



}

template<class T>
bool PriorityQueue<T>::dequeue() {
    if(elementCount == 0)
        return false;
    head = head->next;
    elementCount--;
    return true;
}

template<class T>
T &PriorityQueue<T>::peek()  throw(EmptyDataCollectionException) {
    try{
        if(elementCount == 0){
            throw 1;
        }
    }
    catch(int){
        EmptyDataCollectionException("Queue is empty");
    }
}



