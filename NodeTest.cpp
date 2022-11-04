#include "Node.h"

using namespace std;

int main(){
    Node* n = new Node(5);
    Node* c1 = new Node(3);
    Node* c2 = new Node(7);
    cout << n->getData() << endl;
    n->setLeftChild(c1);
    n->setRightChild(c2);
    cout << n->getLeftChild() << endl;
    cout << n->getRightChild() << endl;
    cout << n->getLeftChild()->getData() << endl;
    cout << n->getRightChild()->getData() << endl;
    return 0;
}