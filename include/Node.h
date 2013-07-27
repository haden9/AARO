#ifndef NODE_H
#define NODE_H

#include <string>

//Forward Declarations
class Edge;

typedef std::vector<Edge*> Edges;

class Node
{
    public:
        Node(std::string prov, double weight=0, bool status=false);
        virtual ~Node();
        //Accessors
        double getCurrentWeight();
        bool getStatus();
        std::string getProvince();
        Edges *getEdges();
        //Mutators
        void setCurrentWeight(double value);
        void setStatus(bool value);
        void addEdge(Edge *e);
        void removeEdge(Edge *e);
    protected:
    private:
        Edges *elist;
        std::string province;
        double currentWeight;
        bool status;


};

#endif // NODE_H
