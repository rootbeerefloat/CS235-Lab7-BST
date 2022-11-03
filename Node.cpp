#pragma once

#include <iostream>
#include "Node.h"

Node::Node(){}
Node::~Node(){}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData(){}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild(){}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild(){}