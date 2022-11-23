#include <iostream>
#include "BST.h"

using namespace std;

void printTree(Node* node, int level) {
    if (node == NULL) return;
    printTree(node->getRightChild(), level + 1);
    for (int i = 0; i < level; i++) cout << "   ";
    cout << node->getData() << endl;
    printTree(node->getLeftChild(), level + 1);
}

void printDeets(Node* node, int level = 0) {
    if (node == NULL) return;
    cout << "Node: " << node->getData() << " (" << node << ") Left: " << node->getLeftChild() << " Right: " << node->getRightChild() << " Level: " << level << endl;
    printDeets(node->getLeftChild(), level + 1);
    printDeets(node->getRightChild(), level + 1);
}

void removeNode(int value, BST*& tree, bool details = false){
    cout << "================================================================" << endl;
    if(tree->remove(value)){
        printTree(tree->getRoot(), 0);
        if (details) printDeets(tree->getRoot(), 0);
    }
    else cout << "Failed to remove " << value << endl;
}

int main(){
    BST* tree = new BST();
    tree->add(1);
    tree->add(2);
    tree->add(3);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->add(4);
    tree->add(5);
    tree->add(6);
    tree->add(10);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->add(8);
    tree->add(7);
    tree->add(9);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(11);
    tree->remove(10);
    tree->remove(9);
    tree->remove(6);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(8);
    tree->remove(7);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(5);
    tree->remove(4);
    tree->remove(3);
    tree->remove(2);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->clear();
    printTree(tree->getRoot(), 0);
    delete tree;
    cout << "Test complete" << endl;
}