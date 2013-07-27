#ifndef NODE_H
#define NODE_H

//Forward Declarations
class Edge;
class Province;

typedef std::vector<Edge*> Edges;

class Node
{
    public:
        Node(Province *prov, double weight=0, bool status=false);
        virtual ~Node();
        //Accessors
        double getCurrentWeight();
        bool getStatus();
        Province *getProvince();
        Edges *getEdges();
        //Mutators
        void setCurrentWeight(double value);
        void setStatus(bool value);
        void addEdge(Edge *e);
        void removeEdge(Edge *e);
    protected:
    private:
        Edges *elist;
        Province *province;
        double currentWeight;
        bool status;


};

#endif // NODE_H
