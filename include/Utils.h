#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Node.h"

using namespace std;

class Utils
{
    public:
        static double getFastestPath(string origin, string destination);
        static double getShortestDistance(string origin, string destination);
        static Node *getShortestVectorNode(Node *n);
    protected:
    private:
};

#endif // UTILS_H
