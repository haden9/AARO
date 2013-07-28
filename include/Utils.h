#ifndef UTILS_H
#define UTILS_H

//Forward Declarations
class Node;
class Edge;

typedef std::vector<Node*> Nodes;

class Utils
{
    public:
        Utils(Nodes *graphNodes);
        virtual ~Utils();
        Nodes *getFastestPath(Node *origin, Node *destination);
        Nodes *getShortestPath(Node *origin, Node *destination, double currentDistance=0);
    private:
        Nodes *graphNodes;
};

#endif // UTILS_H
