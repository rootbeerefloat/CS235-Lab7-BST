#include "BST.h"

BST::BST() {
    root = NULL;
}
BST::~BST() {}

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node * BST::getRootNode() const {
    return root;
}

Node * BST::getRoot() const {
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data) {
    return search(root, data);
}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data) {
    return searchRemove(root, data);
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {}

bool BST::search(Node *&current, int newData) {
    if (root == NULL) {
        root = new Node(newData);
        //cout << "root is null, inserting " << newData << endl;
        return true;
    }
    if (current->getData() == newData) {
        //cout << "Current is equal to newData (" << newData << ")" << endl;
        return false;
    }
    else if (current->getData() > newData) {
        if (current->getLeftChild() == NULL) {
            current->setLeftChild(new Node(newData));
            //cout << "Inserting " << newData << " to the left of " << current->getData() << endl;
            return true;
        }
        else {
            Node *temp = current->getLeftChild();
            return search(temp, newData);
        }
    }
    else {
        if (current->getRightChild() == NULL) {
            current->setRightChild(new Node(newData));
            //cout << "Inserting " << newData << " to the right of " << current->getData() << endl;
            return true;
        }
        else {
            Node *temp = current->getRightChild();
            return search(temp, newData);
        }
    }
}

bool BST::searchRemove(Node *&current, int oldData) {
    if (root == NULL) {
        return false;
    }
    if (current->getData() == oldData) {
        if (current->getLeftChild() == NULL && current->getRightChild() == NULL) {
            cout << "Found " << oldData << " and it has no children" << endl;
            if (previousNode->getLeftChild() == current) {
                previousNode->setLeftChild(NULL);
            }
            else {
                previousNode->setRightChild(NULL);
            }
            delete current;
            current = NULL;
            return true;
        }
        else if (current->getLeftChild() == NULL) {
            cout << "Found " << oldData << " and it has a right child" << endl;
            Node *temp = current->getRightChild();
            current->setData(temp->getData());
            current->setRightChild(temp->getRightChild());
            current->setLeftChild(temp->getLeftChild());
            delete temp;
            return true;
        }
        else if (current->getRightChild() == NULL) {
            cout << "Found " << oldData << " and it has a left child" << endl;
            Node *temp = current->getLeftChild();
            current->setData(temp->getData());
            current->setRightChild(temp->getRightChild());
            current->setLeftChild(temp->getLeftChild());
            delete temp;
            return true;
        }
        else {
            cout << "Found " << oldData << " and it has two children" << endl;
            Node *temp = current->getRightChild();
            while (temp->getLeftChild() != NULL) {
                temp = temp->getLeftChild();
            }
            current->setData(temp->getData());
            Node* temp2 = current->getRightChild();
            return searchRemove(temp2, temp->getData());
        }
    }
    else if (current->getData() > oldData) {
        if (current->getLeftChild() == NULL) {
            return false;
        }
        else {
            Node *temp = current->getLeftChild();
            previousNode = current;
            return searchRemove(temp, oldData);
        }
    }
    else {
        if (current->getRightChild() == NULL) {
            return false;
        }
        else {
            Node *temp = current->getRightChild();
            previousNode = current;
            return searchRemove(temp, oldData);
        }
    }
}