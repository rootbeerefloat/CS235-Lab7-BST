#include <iostream>
#include "BST.h"

using namespace std;

void printTree(Node* node, int level) {
    if (node == NULL) return;
    printTree(node->getRight(), level + 1);
    for (int i = 0; i < level; i++) cout << "   ";
    cout << node->getData() << endl;
    printTree(node->getLeft(), level + 1);
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
    tree->add(21);
    tree->add(22);
    tree->add(23);
    tree->add(24);
    tree->add(25);
    tree->add(26);
    tree->add(27);
    tree->add(28);
    tree->add(29);
    tree->add(30);
    tree->add(31);
    tree->add(32);
    tree->add(33);
    tree->add(34);
    tree->add(35);
    tree->add(36);
    tree->add(37);
    tree->add(38);
    tree->add(39);
    tree->add(40);
    tree->add(41);
    tree->add(42);
    tree->add(43);
    tree->add(44);
    tree->add(45);
    tree->add(46);
    tree->add(47);
    tree->add(48);
    tree->add(49);
    tree->add(50);
    tree->add(51);
    tree->add(52);
    tree->add(53);
    tree->add(54);
    tree->add(55);
    tree->add(56);
    tree->add(57);
    tree->add(58);
    tree->add(59);
    tree->add(60);
    tree->add(61);
    tree->add(62);
    tree->add(63);
    tree->add(64);
    tree->add(65);
    tree->add(66);
    tree->add(67);
    tree->add(68);
    tree->add(69);
    tree->add(70);
    printTree(tree->getRoot(), 0);
}