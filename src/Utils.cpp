#include <vector>
#include <stdlib.h>

#include "Utils.h"
#include "Node.h"
#include "Edge.h"

using namespace std;

Utils::Utils(vector<Node*> *nodeList)
    : graphNodes(nodeList)
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

//Dijkstra's Algorithm + velocity ( v = d / t ) in vector
vector<Node*> *Utils::getFastestPath(Node *origin, Node *destination) {
    calculateFastestRoutes(origin, destination);
    return graphNodes;
}

//Dijkstra's Algorithm
vector<Node*> *Utils::getShortestPath(Node *origin, Node *destination) {

    calculateShortestRoutes(origin, destination);
    return graphNodes;
}

void Utils::calculateFastestRoutes(Node *origin, Node *destination) {

    //if destination has been visited
    if(destination->getStatus())
        return;

    //Check all edges contained in origin node
    for (unsigned int i = 0; i < origin->getEdges()->size(); i++) {

        //get edge ptr from edges at index i
        Edge *e = origin->getEdges()->at(i);
        //get the current ptr to the destination node referenced by edge
        Node *n = e->getDestination();

        //if node has not been visited
        if(!n->getStatus()) {

            //tentativeDistance = weight in node (shortest distance to node) + edge magnitude
            double tentativeDistance = origin->getCurrentWeight() + e->getMagnitude();
            //tentativeTime = tentativeDistance / maxVelocity of Edge
            double tentativeTime = tentativeDistance / e->getMaxVelocity();

            //compares if current lowest edge is lower than the next or 0
            if(tentativeDistance < n->getCurrentWeight() || n->getCurrentWeight() == 0)
                //sets the new currentWeight of destination node
                n->setCurrentWeight(tentativeDistance);
            if(tentativeTime < n->getCurrentETA() || n->getCurrentETA() == 0)
                //sets the new currentWeight of destination node
                n->setCurrentETA(tentativeTime);

        }
    }

    Node *nearest;

    //Keeps the list sorted by node weight
    sortListByTime();

    //finds the nearest node (shortest relative distance) on the list
    for (unsigned int i = 0; i < graphNodes->size(); i++) {
        if(graphNodes->at(i)->getCurrentWeight() > 0) {
            nearest = graphNodes->at(i);
            break;
        }
    }

    //recursive call
    calculateFastestRoutes(nearest, destination);
}

void Utils::calculateShortestRoutes(Node *origin, Node *destination) {

    //if destination has been visited
    if(destination->getStatus())
        return;

    //Check all edges contained in origin node
    for (unsigned int i = 0; i < origin->getEdges()->size(); i++) {

        //get edge ptr from edges at index i
        Edge *e = origin->getEdges()->at(i);
        //get the current ptr to the destination node referenced by edge
        Node *n = e->getDestination();

        //if node has not been visited
        if(!n->getStatus()) {

            //tentativeDistance = weight in node (shortest distance to node) + edge magnitude
            double tentativeDistance = origin->getCurrentWeight() + e->getMagnitude();

            //compares if current lowest edge is lower than the next or 0
            if(tentativeDistance < n->getCurrentWeight() || n->getCurrentWeight() == 0)
                //sets the new currentWeight of destination node
                n->setCurrentWeight(tentativeDistance);
        }
    }

    Node *nearest;

    //Keeps the list sorted by node weight
    sortListByWeight();

    //finds the nearest node (shortest relative distance) on the list
    for (unsigned int i = 0; i < graphNodes->size(); i++) {
        if(graphNodes->at(i)->getCurrentWeight() > 0) {
            nearest = graphNodes->at(i);
            break;
        }
    }

    //recursive call
    calculateShortestRoutes(nearest, destination);
}

void Utils::sortListByWeight() {

    unsigned int lSize = graphNodes->size()-1;
    for(unsigned int i = 0; i < lSize; i++)
        for(unsigned int r = 0; r < lSize-i; r++) {

            Node *a = graphNodes->at(r);
            Node *b = graphNodes->at(r+1);

            if(a->getCurrentWeight() > b->getCurrentWeight())
                swap(graphNodes[r], graphNodes[r+1]);
        }
}

void Utils::sortListByTime() {

    unsigned int lSize = graphNodes->size()-1;
    for(unsigned int i = 0; i < lSize; i++)
        for(unsigned int r = 0; r < lSize-i; r++) {

            Node *a = graphNodes->at(r);
            Node *b = graphNodes->at(r+1);

            if(a->getCurrentETA() > b->getCurrentETA())
                swap(graphNodes[r], graphNodes[r+1]);
        }
}
