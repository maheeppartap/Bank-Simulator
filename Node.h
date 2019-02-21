
#pragma once

template<class T>
class Node
{
public:
	// Public attributes - Why are the attributes public?
	T data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors (why no destructor?)
	Node();
	Node(T theData);
	Node(T theData, Node* theNextNode);

}; // end Node
template <class T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
}

template <class T>
Node<T>::Node(T theData)
{
	data = theData;
	next = nullptr;
}

template <class T>
Node<T>::Node(T theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}
