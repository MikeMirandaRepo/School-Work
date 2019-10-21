
#include "node.h"

node::node() : value(0), nextNode(NULL){
    
}

node::node(int _value): value(_value), nextNode(NULL) {
}

node::node(int _value, node *_nextNode) : value(_value), nextNode(_nextNode) {
    
}

node::node(node& orig) : value(orig.GetValue()), nextNode(orig.GetNextNode()) {
 
}

node::~node() {
}

void node::printAll(){
    cout << "Node content:" << endl;
    cout << value << endl;
    cout << nextNode << endl;
}
