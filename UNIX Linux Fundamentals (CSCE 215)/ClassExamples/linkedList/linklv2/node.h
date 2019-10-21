#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <iostream>

using namespace std;

class node {
public:
    node();
    node(int);
    node(int, node *);
    node(node& orig);
    ~node();

    void printAll();
    
    node* GetNextNode() {
        return nextNode;
    }

    void SetNextNode(node* _nextNode) {
        nextNode = _nextNode;
    }

    int GetValue() {
        return value;
    }

    void SetValue(int _value) {
        value = _value;
    }
    
private:
    int value;
    node *nextNode;

};

#endif /* NODE_H */

