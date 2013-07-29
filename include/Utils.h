#ifndef UTILS_H
#define UTILS_H

//Forward Declarations
class Node;
class Edge;

using std::swap;
using namespace std;

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
        void calculateFastestRoutes(Node *origin, Node *destination);
        void calculateShortestRoutes(Node *origin, Node *destination);
        void sortListByWeight();
        void sortListByTime();

};
#endif // UTILS_H
