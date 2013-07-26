#ifndef NODE_H
#define NODE_H

#include <vector>
#include "province.h"

typedef vector list;

class Node
{
    public:
        Node(Province *p, double currentWeight=0, bool status=false);
        virtual ~Node();
        double getCurrentWeight();
        bool getStatus();
        Province *getProvince();
        list<Vector> *getVectorList();
        void setCurrentWeight(double value);
        void setStatus(bool value);
        void addVector(Vector v);
        void removeVector(Vector v);
    protected:
    private:
        double currentWeight;
        bool status;
        Province *province;
        list<Vector> *vectorList; //list of connected vectors to this node
};

#endif // NODO_H
