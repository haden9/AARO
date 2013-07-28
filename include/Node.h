#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

//Forward Declarations
class Edge;

class Node
{
    public:
        Node(string prov, double weight=0, bool status=false);
        virtual ~Node();
        //Accessors
        double getCurrentWeight();
        double getCurrentETA();
        bool getStatus();
        string getProvince();
        vector<Edge*> getEdges();
        //Mutators
        void setCurrentWeight(double value);
        void setCurrentETA(double value);
        void setStatus(bool value);
        void addEdge(Edge *e);
        void removeEdge(Edge *e);
    protected:
    private:
        vector<Edge*> elist;
        string province;
        double currentWeight;
        double currentETA;
        bool status;


};

#endif // NODE_H
