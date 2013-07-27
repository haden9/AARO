#ifndef EDGE_H
#define EDGE_H

//Forward Declarations
class Node;

class Edge
{
    public:
        Edge(double magnitude, double maxVelocity, Node *origin, Node *destination);
        virtual ~Edge();
        double getMagnitude();
        double getMaxVelocity();
        Node* getOrigin();
        Node* getDestination();
    protected:
    private:
        // magnitude = absolute value
        // velocity = distance / time
        double magnitude, maxVelocity;
        //origin = origin vertex or node
        //destination = destination vertex or node
        Node *origin, *destination;
};

#endif // EDGE_H
