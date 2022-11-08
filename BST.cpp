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
        //cout <<"Node is null" << endl;
        return;
    }
    //else cout <<"Input is " << _root->getData() << " (" << _root << ")" << endl;
    Node* left = _root->getLeftChild();
    //if (_root == root) //cout <<"Got left child as " << left << endl;
    //cout <<"Got left child as " << left << endl;
    Node* right = _root->getRightChild();
    _root->setLeftChild(NULL);
    _root->setRightChild(NULL);
    //if (_root == root) //cout <<"Got right child as " << right << ", clearing left" << endl;
    //cout <<"Got right child as " << right << ", clearing left" << endl;
    recursiveClear(left);
    //if (_root == root) //cout <<"Left cleared, Calling clear right" << endl;
    //cout <<"Left cleared, Calling clear right" << endl;
    recursiveClear(right);
    //if (_root == root) //cout <<"Right clear, deleting" << endl;
    //cout <<"Right clear, deleting " << _root << endl;
    //cout <<"Deleting node: " << _root->getData() << " (" << _root << ")" << endl;
    delete _root;
    //if (_root == root) //cout <<"Deleted!" << endl;
    //cout <<"Deleted!" << endl;
    return;
}

bool BST::search(Node *&current, int newData) {
    if (root == NULL) {
        root = new Node(newData);
        //cout <<"Allocating " << root << endl;
        //cout <<"root is null, inserting " << newData << endl;
        return true;
    }
    if (current->getData() == newData) {
        //cout <<"Current is equal to newData (" << newData << ")" << endl;
        return false;
    }
    else if (current->getData() > newData) {
        if (current->getLeftChild() == NULL) {
            current->setLeftChild(new Node(newData));
            //cout <<"Inserting " << newData << " to the left of " << current->getData() << endl;
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
            //cout <<"Inserting " << newData << " to the right of " << current->getData() << endl;
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
                //cout <<"Deleting " << temps << endl;
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
            current->setLeftChild(NULL);
            current->setRightChild(NULL);
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
            current->setLeftChild(NULL);
            current->setRightChild(NULL);
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
            //cout <<"nextLowest is " << nextLowest << " (" << nextLowest->getData() << ")" << endl;
            int data = nextLowest->getData();
            searchRemove(root, data);
            current->setData(data);
            // if (temp == current->getLeftChild()){
            //     //cout <<"case 1" << endl;
            //     Node* temp2 = current->getLeftChild();
            //     if (current->getLeftChild()->getLeftChild() == NULL) {
            //         current->setLeftChild(NULL);
            //     }
            //     else {
            //         current->setLeftChild(current->getLeftChild()->getLeftChild());
            //     }
            //     temp2->setRightChild(NULL);
            //     temp2->setLeftChild(NULL);
            //     delete temp2;
            // }
            // else if (temp == current->getLeftChild()->getRightChild()){
            //     //cout <<"case 2" << endl;
            //     Node* temp2 = current->getLeftChild()->getRightChild();
            //     current->getLeftChild()->setRightChild(NULL);
            //     temp2->setRightChild(NULL);
            //     temp2->setLeftChild(NULL);
            //     delete temp2;
            // }
            // else {
            //     //cout <<"case 3" << endl;
            //     Node* temp2 = current->getLeftChild();
            //     searchRemove(temp2, temp->getData());
            // }
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