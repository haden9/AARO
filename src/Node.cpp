#include "Node.h"

Node::Node(Province *p, double currentWeight, bool status)
    : province(p)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

double Node::getCurrentWeight() {
    return currentWeight;
}

bool Node::getStatus() {
    return status;
}

Province* Node::getProvince() {
    return province;
}

void Node::setCurrentWeight(double value) {
    currentWeight = value;
}

void Node::setStatus(bool value) {
    status = value;
}
