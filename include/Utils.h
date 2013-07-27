#ifndef UTILS_H
#define UTILS_H

//Forward Declarations
class Node;
class Edge;

typedef std::vector<Node*> Nodes;

class Utils
{
    public:
        static double getFastestPath(Node *origin, Node *destination);
        static double *getShortestPath(Node *origin, Node *destination, double currentDistance=0);
    protected:
    private:
};

#endif // UTILS_H
