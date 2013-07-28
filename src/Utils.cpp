#include <vector>
#include <stdlib.h>

#include "Utils.h"
#include "Node.h"
#include "Edge.h"


Utils::Utils(Nodes *nodeList)
    : graphNodes(nodeList)
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

//Dijkstra's Algorithm + velocity ( v = d / t ) in vector
Nodes *getFastestPath(Node *origin, Node *destination) {
    return NULL;
}

//Dijkstra's Algorithm
Nodes *getShortestPath(Node *origin, Node *destination, double currentDistance) {

    //defines the list of visited nodes
    Nodes* nodeList = (Nodes*)malloc(sizeof(nodeList));
    //adds a new visited node to the nodeList
    nodeList->push_back(origin);

    free(nodeList);

    if(origin != destination) {

        Node *nextNode;
        double edgeDistance = 0, tentativeDistance = 0;

        //Check all edges contained in origin node
        for (unsigned int i = 0; i < origin->getEdges()->size(); i++) {

            //get edge ptr from edges at index i
            Edge *e = origin->getEdges()->at(i);
            //get the current ptr to the destination node referenced by edge
            Node *n = e->getDestination();

            //if node status == visited omits node
            if(n->getStatus())
                continue;

            //sets the new currentWeight of destination node
            tentativeDistance = currentDistance + e->getMagnitude(); // tentativeDistance = distance traveled + edge magnitude
            if(tentativeDistance < n->getCurrentWeight())
                n->setCurrentWeight(tentativeDistance);

            //compares if current lowest edge is lower than the next or 0
            if(e->getMagnitude() < edgeDistance || edgeDistance == 0) {
                //sets the current edge distance
                edgeDistance = e->getMagnitude();
                //sets the next node to be visited
                nextNode = n;
            }
        }

        //Nodo origen marcado como visitado
        origin->setStatus(true);

        return getShortestPath(nextNode, destination, tentativeDistance);
    } else
        return nodeList;
}

