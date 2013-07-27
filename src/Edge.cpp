#include "Edge.h"

Edge::Edge(double magnitude, double maxVelocity, Node *origin, Node *destination)
    : magnitude(magnitude), maxVelocity(maxVelocity), origin(origin), destination(destination)
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

Node* Edge::getOrigin() {
    return origin;
}

Node* Edge::getDestination() {
    return destination;
}
