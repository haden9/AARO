#ifndef EDGE_H
#define EDGE_H

//Forward Declarations
class Node;

class Edge
{
    public:
        Edge(double magnitude, double maxVelocity, Node *destination);
        virtual ~Edge();
        double getMagnitude();
        double getMaxVelocity();
        Node* getDestination();
    protected:
    private:
        // magnitude = absolute value
        // velocity = distance / time
        double magnitude, maxVelocity;
        //destination = destination vertex or node
        Node *destination;
};

#endif // EDGE_H
