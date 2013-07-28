#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

#include "Edge.h"

class Node
{
    public:
        Node(std::string prov, double weight=0, bool status=false);
        virtual ~Node();
        //Accessors
        double getCurrentWeight();
        bool getStatus();
        std::string getProvince();
        std::vector<Edge*> getEdges();
        //Mutators
        void setCurrentWeight(double value);
        void setStatus(bool value);
        void addEdge(Edge *e);
        void removeEdge(Edge *e);
    protected:
    private:
        std::vector<Edge*> edgeList;
        std::string province;
        double currentWeight;
        bool status;


};

#endif // NODE_H
