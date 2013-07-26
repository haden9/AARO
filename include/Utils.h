#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Node.h"

using namespace std;

class Utils
{
    public:
        static double getFastestPath(Node *origin, Node *destination);
        static double getShortestPath(Node *origin, Node *destination);
        static Node *getShortestVectorNode(Node *n);
    protected:
    private:
};

#endif // UTILS_H
