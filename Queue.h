/*
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Maheeppartap Singh
 * Date: 2018-02-04
 */
#include "EmptyDataCollectionException.h"

template <class ElementType> class Queue {
    private:
        static ElementType const INITIAL_SIZE = 6;
        ElementType* elements;

        ElementType elementCount;  // number of elements in the queue
        ElementType capacity;      // number of cells in the array
        ElementType frontindex;    // index the topmost element
        ElementType backindex;     // index where the next element will be placed

    public:
        // Desc:  Constructor
        Queue();

        //Desc : Destructor
        ~Queue();


        // Desc:  Inserts element x at the back (O(1))
        bool enqueue(ElementType x);


        // Desc:  Removes the frontmost element (O(1))
        //  Pre:  Queue not empty
        bool dequeue();


        // Desc:  Returns a copy of the frontmost element (O(1))
        //  Pre:  Queue not empty
        ElementType & peek(EmptyDataCollectionException) const;


        // Desc:  Returns true if and only if queue empty (O(1))
        bool isEmpty() const;
};


// Desc:  Constructor
template <class ElementType>
Queue<ElementType>::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
    elements = new ElementType[capacity];
} // constructor


// Desc:  Inserts element x at the back (O(1))
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType x) {
    ElementType oldCount = elementCount;
    if(elementCount == capacity){   //Checks if the Queue is full or not
        ElementType newSize = capacity*2;  //Doubles the capacity
        auto new_arr = new ElementType[newSize];
        ElementType i,j = 0;
        for(i = frontindex ; j < capacity ; i = ( i + 1)%capacity){
            new_arr[j] = elements[i];
            j++;
        }
        delete elements;    //Deleting the old Queue
        elements = new_arr;
        backindex = capacity;
        capacity = newSize;
        frontindex = 0;
    }

    elementCount++;
    elements[backindex] = x;    //Insert the new element
    backindex = (backindex + 1) % capacity;
    return elementCount>oldCount;
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
template <class ElementType>
 bool Queue<ElementType>::dequeue() {
    ElementType oldCount = elementCount;
    if( elementCount < capacity/4 && elementCount/4 > INITIAL_SIZE){    //Checks if the Queue is 1/4 of the capacity
        auto * new_arr = new ElementType[capacity/4];                      //Making a new array with 1/4th of the capacity to save space
        ElementType j = 0;
        for(ElementType i = frontindex ; j < capacity ; i = ( i + 1)%capacity){
            new_arr[j] = elements[i];
            j++;
        }
        delete elements;
        elements = new_arr;
        frontindex = (frontindex + 1) % capacity;
        return elementCount<oldCount;
    }
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    return elementCount<oldCount;

} // dequeue
// Desc:  Returns true if and only if queue empty (O(1))
template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}
template <class ElementType>
Queue<ElementType>::~Queue() {
    delete elements;
}

// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty


template<class ElementType>
ElementType & Queue<ElementType>::peek(EmptyDataCollectionException) const {
    try{
        if (elementCount == 0)
            throw 1;
        return frontindex;
    }
    catch(int){
        EmptyDataCollectionException("Queue is empty");
    }
}
//top

// isempty




