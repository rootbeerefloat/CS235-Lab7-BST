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
NodeInterface * BST::getRootNode() const {
    return rootInterface;
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
    return false;
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear() {}

bool BST::search(Node *&current, int newData) {
    if (root == NULL) {
        root = new Node(newData);
        cout << "root is null, inserting " << newData << endl;
        return true;
    }
    if (current->getData() == newData) {
        cout << "Current is equal to newData (" << newData << ")" << endl;
        return false;
    }
    else if (current->getData() > newData) {
        if (current->getLeft() == NULL) {
            current->setLeftChild(new Node(newData));
            cout << "Inserting " << newData << " to the left of " << current->getData() << endl;
            return true;
        }
        else {
            Node *temp = current->getLeft();
            return search(temp, newData);
        }
    }
    else {
        if (current->getRight() == NULL) {
            current->setRightChild(new Node(newData));
            cout << "Inserting " << newData << " to the right of " << current->getData() << endl;
            return true;
        }
        else {
            Node *temp = current->getRight();
            return search(temp, newData);
        }
    }
}