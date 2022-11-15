#include "BST.h"

BST::BST() {
    root = NULL;
}
BST::~BST() {
    clear();
}

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
void BST::clear() {
    delete root;
    root = NULL;
    // recursiveClear(root);
    // root = NULL;
}

void BST::recursiveClear(Node*& _root) {
    if (_root == NULL) {
        return;
    }
    if (_root->getLeftChild() != NULL) {
        Node* left = _root->getLeftChild();
        recursiveClear(left);
    }
    if (_root->getRightChild() != NULL) {
        Node* right = _root->getRightChild();
        recursiveClear(right);
    }
    delete _root;
    return;
}

bool BST::search(Node *&current, int newData) {
    if (root == NULL) {
        root = new Node(newData);
        return true;
    }
    if (current->getData() == newData) {
        return false;
    }
    else if (current->getData() > newData) {
        if (current->getLeftChild() == NULL) {
            current->setLeftChild(new Node(newData));
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
    if (current == NULL){
        return false;
    }
    //cout <<"Current is " << current->getData() << " and oldData is " << oldData << endl;
    if (current->getData() == oldData) {
        if (current->getLeftChild() == NULL && current->getRightChild() == NULL) {
            //cout <<"Found " << oldData << " at " << current << " and it has no children" << endl;
            if (current == root) {
                Node * temps = root;
                root = NULL;
                delete temps;
                return true;
            }
            else{
                if (previousNode->getLeftChild() == current) {
                    previousNode->setLeftChild(NULL);
                }
                else {
                    previousNode->setRightChild(NULL);
                }
            }
            delete current;
            return true;
        }
        else if (current->getLeftChild() == NULL) {
            //cout <<"Found " << oldData << " and it has a right child" << endl;
            //cout <<"Current is " << current << " (" << current->getData() << ")" << endl;
            Node * temp = current->getRightChild();
            if (current != root){
                if (previousNode->getLeftChild() == current) {
                    previousNode->setLeftChild(temp);
                }
                else {
                    previousNode->setRightChild(temp);
                }
            }
            //cout <<"Deleting " << current << " (" << current->getData() << ")" << endl;
            if (current == root) {
                delete current;
                root = temp;
            }
            else {
                delete current;
            }
            return true;
        }
        else if (current->getRightChild() == NULL) {
            //cout <<"Found " << oldData << " and it has a left child" << endl;
            //cout <<"Current is " << current << " (" << current->getData() << ")" << endl;
            Node * temp = current->getLeftChild();
            if (current != root){
                if (previousNode->getLeftChild() == current) {
                    previousNode->setLeftChild(temp);
                }
                else {
                    previousNode->setRightChild(temp);
                }
            }
            //cout <<"Deleting " << current << " (" << current->getData() << ")" << endl;
            if (current == root) {
                delete current;
                root = temp;
            }
            else {
                delete current;
            }
            return true;
        }
        else {
            //cout <<"Found " << oldData << " and it has two children" << endl;
            Node *  nextLowest = current->getLeftChild();
            while (nextLowest->getRightChild() != NULL) {
                nextLowest = nextLowest->getRightChild();
            }
            Node * nextLowestParent = NULL;
            if (current->getLeftChild() == nextLowest){
                nextLowestParent = current;
            }
            else if (current->getLeftChild()->getRightChild() == nextLowest) {
                nextLowestParent = current->getLeftChild();
            }
            else {
                Node * templook = current->getLeftChild();
                while (templook->getRightChild() != nextLowest) {
                    templook = templook->getRightChild();
                }
                nextLowestParent = templook;
            }
            //cout <<"nextLowest is " << nextLowest << " (" << nextLowest->getData() << ")" << endl;
            nextLowestParent->setRightChild(nextLowest->getLeftChild());
            nextLowest->setLeftChild(current->getLeftChild());
            nextLowest->setRightChild(current->getRightChild());
            if (current != root){
                if (previousNode->getLeftChild() == current) {
                    previousNode->setLeftChild(nextLowest);
                }
                else {
                    previousNode->setRightChild(nextLowest);
                }
            }
            else {
                root = nextLowest;
            }
            return true;
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