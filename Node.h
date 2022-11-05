#pragma once

#include <iostream>
#include "NodeInterface.h"

using namespace std;

class Node: public NodeInterface {
private:
    int data;
    Node* left;
    Node* right;
	NodeInterface* leftChild;
	NodeInterface* rightChild;
public:
	Node(int _data);
	~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

	Node * getLeft() const;
	Node * getRight() const;

	void setLeftChild(Node* _left);
	void setRightChild(Node* _right);

};