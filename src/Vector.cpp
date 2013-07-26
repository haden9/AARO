#include "Vector.h"

Vector::Vector(double magnitude, double maxVelocity, Node *origin, Node *destination)
    : magnitude(magnitude), maxVelocity(maxVelocity), origin(origin), destination(destination)
{
    //ctor
}

Vector::~Vector()
{
    //dtor
}

double Vector::getMagnitude() {
    return magnitude;
}

double Vector::getMaxVelocity() {
    return maxVelocity;
}

Node* Vector::getOrigin() {
    return origin;
}

Node* Vector::getDestination() {
    return destination;
}
