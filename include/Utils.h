#ifndef UTILS_H
#define UTILS_H

//Forward Declarations
class Node;
class Edge;

typedef std::vector<Node*> Nodes;

using std::swap;

class Utils
{
    public:
        Utils(Nodes *graphNodes);
        virtual ~Utils();
        //Methods
        Nodes *getFastestPath(Node *origin, Node *destination);
        Nodes *getShortestPath(Node *origin, Node *destination);

    private:
        Nodes *graphNodes;
        void calculateFastestRoutes(Node *origin, Node *destination);
        void calculateShortestRoutes(Node *origin, Node *destination);
        void sortListByWeight();
        void sortListByTime();

};
#endif // UTILS_H
