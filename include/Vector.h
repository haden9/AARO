#ifndef VECTOR_H
#define VECTOR_H

#include "Node.h"

class Vector
{
    public:
        Vector(double magnitude, double maxVelocity, Node *origin, Node *destination);
        virtual ~Vector();
        double getMagnitude();
        double getMaxVelocity();
        Node *getOrigin();
        Node *getDestination();
    protected:
    private:
        // magnitude = absolute value
        // velocity = distance / time
        double magnitude, maxVelocity;
        //origin = origin vertex or node
        //destination = destination vertex or node
        Node *origin, *destination;
};

#endif // VECTOR_H
