#include <vector>
#include <stdlib.h>
#include <algorithm>

#include "Utils.h"
#include "Node.h"
#include "Edge.h"


Utils::Utils(vector<Node*> *nodeList)
    : graphNodes(nodeList), visitedNodes(new vector<Node*>())
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
    sortListByTime(visitedNodes);
    return visitedNodes;
}

//Dijkstra's Algorithm
vector<Node*> *Utils::getShortestPath(Node *origin, Node *destination) {

    calculateShortestRoutes(origin, destination);
    sortListByWeight(visitedNodes);
    return visitedNodes;
}

void Utils::calculateFastestRoutes(Node *origin, Node *destination) {

    //if destination has been visited
    if(!destination->getStatus()) {

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

        //after all edges calculated, sets status as visited
        origin->setStatus(true);

        //adds the node to the visitedNodes list
        visitedNodes->push_back(origin);

        //remove the node from the graphNodes list
        removeNodeFromList(origin);

        //finds the nearest node not visited (shortest ETA) on the list
        Node *nearest = getNearestNodeByETA();

        //recursive call
        calculateFastestRoutes(nearest, destination);

    } else
        return;
}

void Utils::calculateShortestRoutes(Node *origin, Node *destination) {

    //if destination has been visited
    if(!destination->getStatus()) {

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

        //after all edges calculated, sets status as visited
        origin->setStatus(true);

        //adds the node to the visitedNodes list
        visitedNodes->push_back(origin);

        //remove the node from the graphNodes list
        removeNodeFromList(origin);

        //finds the nearest node not visited (shortest ETA) on the list
        Node *nearest = getNearestNodeByWeight();

        //recursive call
        calculateShortestRoutes(nearest, destination);
    } else
        return;

}

Node* Utils::getNearestNodeByWeight() {

    Node *nearest = graphNodes->at(0);
    for (unsigned int i = 1; i < graphNodes->size(); i++) {
        if( graphNodes->at(i)->getCurrentWeight() < nearest->getCurrentWeight() && graphNodes->at(i)->getCurrentWeight() != 0)
            nearest = graphNodes->at(i);
    }
    return nearest;
}

Node* Utils::getNearestNodeByETA() {

    Node *nearest = graphNodes->at(0);
    for (unsigned int i = 1; i < graphNodes->size(); i++) {
        if( graphNodes->at(i)->getCurrentETA() < nearest->getCurrentETA())
            nearest = graphNodes->at(i);
    }
    return nearest;
}

void Utils::removeNodeFromList(Node *node) {

    for (unsigned int i = 1; i < graphNodes->size(); i++) {
        if(graphNodes->at(i) == node)
            graphNodes->erase(graphNodes->begin()+i);
    }


}

void Utils::sortListByWeight(vector<Node*> *list) {

    unsigned int lSize = list->size()-1;
    for(unsigned int i = 0; i < lSize; i++)
        for(unsigned int r = 0; r < lSize-i; r++) {

            Node *a = list->at(r);
            Node *b = list->at(r+1);

            if(a->getCurrentWeight() > b->getCurrentWeight())
                swap(list[r], list[r+1]);
        }
}

void Utils::sortListByTime(vector<Node*> *list) {

    unsigned int lSize = list->size()-1;
    for(unsigned int i = 0; i < lSize; i++)
        for(unsigned int r = 0; r < lSize-i; r++) {

            Node *a = list->at(r);
            Node *b = list->at(r+1);

            if(a->getCurrentETA() > b->getCurrentETA())
                swap(list[r], list[r+1]);
        }
}
