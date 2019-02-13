
#pragma once

class Node
{
public:
	// Public attributes - Why are the attributes public?
	int data;     // The data in the node
	Node* next;   // Pointer to next node
	
	// Constructors (why no destructor?)
	Node();
	Node(int theData);
	Node(int theData, Node* theNextNode);

}; // end Node