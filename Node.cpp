#include "Node.h"

Node::Node(int _data){
    data = _data;
    left = NULL;
    right = NULL;
    leftChild = NULL;
    rightChild = NULL;
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
int Node::getData() const{
    return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild() const{
    return leftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild() const{
    return rightChild;
}

void Node::setLeftChild(Node* _left){
    left = _left;
}
void Node::setRightChild(Node* _right){
    right = _right;
}

Node * Node::getLeft() const{
    return left;
}

Node * Node::getRight() const{
    return right;
}