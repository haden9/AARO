#ifndef UTILS_H
#define UTILS_H

//Forward Declarations
class Node;
class Edge;

using std::vector;

class Utils
{
    public:
        Utils(vector<Node*> *graphNodes);
        virtual ~Utils();
        //Methods
        vector<Node*> *getFastestPath(Node *origin, Node *destination);
        vector<Node*> *getShortestPath(Node *origin, Node *destination);

    private:
        vector<Node*> *graphNodes;
        vector<Node*> *visitedNodes;
        void calculateFastestRoutes(Node *origin, Node *destination);
        void calculateShortestRoutes(Node *origin, Node *destination);
        void removeNodeFromList(Node *node);
        void sortListByWeight(vector<Node*> *list);
        void sortListByTime(vector<Node*> *list);
        Node* getNearestNodeByWeight();
        Node* getNearestNodeByETA();
};
#endif // UTILS_H
