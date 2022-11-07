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

int main(){
    BST* tree = new BST();
    tree->add(10);
    tree->add(5);
    tree->add(15);
    tree->add(2);
    tree->add(7);
    tree->add(12);
    tree->add(17);
    tree->add(1);
    tree->add(3);
    tree->add(6);
    tree->add(8);
    tree->add(11);
    tree->add(13);
    tree->add(13);
    tree->add(16);
    tree->add(18);
    tree->add(4);
    tree->add(9);
    tree->add(14);
    tree->add(19);
    tree->add(20);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(4);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(8);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(4);
    printTree(tree->getRoot(), 0);
    cout << "================================================================" << endl;
    tree->remove(10);
    printTree(tree->getRoot(), 0);
}