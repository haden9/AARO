#include "Edge.h"

Edge::Edge(double magnitude, double maxVelocity, Node *destination)
    : magnitude(magnitude), maxVelocity(maxVelocity), destination(destination)
{
    //ctor
}

Edge::~Edge()
{
    //dtor
}

double Edge::getMagnitude() {
    return magnitude;
}

double Edge::getMaxVelocity() {
    return maxVelocity;
}

Node* Edge::getDestination() {
    return destination;
}
