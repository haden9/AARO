
#include <vector>
#include "Node.h"

Node::Node(std::string prov, double weight, bool status)
    : province(prov), currentWeight(weight), status(status)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

//Accessors

double Node::getCurrentWeight() {
    return currentWeight;
}

bool Node::getStatus() {
    return status;
}

std::string Node::getProvince() {
    return province;
}

Edges* Node::getEdges() {
    return elist;
}

//Mutators

void Node::setCurrentWeight(double value) {
    currentWeight = value;
}

void Node::setStatus(bool value) {
    status = value;
}

void Node::addEdge(Edge *e) {
    elist->push_back(e);
}
void Node::removeEdge(Edge *e) {
    //Pendiente
}



