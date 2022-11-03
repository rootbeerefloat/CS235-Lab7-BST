#pragma once

#include <iostream>
#include "Node.h"

Node::Node(){
    data = 0;
    left = NULL;
    right = NULL;
}
Node::~Node(){
    delete left;
    delete right;
}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData(){
    return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node * Node::getLeftChild(){
    return left;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node * Node::getRightChild(){
    return right;
}