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
    tree->add(4);
    tree->add(2);
    tree->add(6);
    tree->add(1);
    tree->add(3);
    tree->add(5);
    tree->add(7);
    printTree(tree->getRoot(), 0);
    removeNode(6, tree);
    removeNode(4, tree, true);
    removeNode(3, tree, true);
    cout << "End of test" << endl;
}