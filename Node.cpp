

#include <cstdio>  // Needed for NULL
#include "Node.h"

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int theData)
{
	data = theData;
	next = NULL;
}

Node::Node(int theData, Node* theNextNode)
{
	data = theData;
	next = theNextNode;
}

// end Node.cpp