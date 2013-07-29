#include <iostream>
#include <fstream>
#include <vector>
#include <rapidxml_utils.hpp>

#include "Node.h"
#include "Edge.h"
#include "Utils.h"

using namespace rapidxml;
using namespace std;

void readXML(vector<Node*>* nodeList);
void createProvinces(vector<Node*>* nodeList, xml_node<> *rootNode);
void addEdgesToProvinces(vector<Node*>* nodeList, xml_node<> *rootNode);
Node *findProvinceNode(vector<Node*>*nodeList, string name);

int main()
{
    vector<Node*> *nodeList = (vector<Node*>*)malloc(sizeof(nodeList));
    readXML(nodeList);
    Utils *u = new Utils(nodeList);

    /*TODO MENU DISPLAY*/

    return 0;
}

void readXML(vector<Node*> *nodeList){

    xml_document<> xDoc;
    xml_node<> * rootNode;

    // Reading the xml file into a vector
    ifstream countryXml("xml/country.xml");
    vector<char> buffer((istreambuf_iterator<char>(countryXml)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parsing the buffer using the xml file parsing library into xDoc
    xDoc.parse<0>(&buffer[0]);

    // Finding the root node
    rootNode = xDoc.first_node("country");

    createProvinces(nodeList, rootNode);
    addEdgesToProvinces(nodeList, rootNode);
}

void createProvinces(vector<Node*>* nodeList, xml_node<> *rootNode){
    // Iterating over the provinces
    for(xml_node<> * provinceNode = rootNode->first_node("province"); provinceNode; provinceNode = provinceNode->next_sibling())
    {
        Node *prov = new Node(provinceNode->first_attribute("name")->value());
        //adds the province node to the nodeList
        nodeList->push_back(prov);
    }
}


void addEdgesToProvinces(vector<Node*>* nodeList, xml_node<> *rootNode){

    for(xml_node<> * provinceNode = rootNode->first_node("province"); provinceNode; provinceNode = provinceNode->next_sibling())
    {
        Node *ori = findProvinceNode(nodeList, provinceNode->first_attribute("name")->value());

        // Iterating over the routes
        for(xml_node<> * routeNode = provinceNode->first_node("route"); routeNode; routeNode = routeNode->next_sibling()) {

            Node *dest = findProvinceNode(nodeList, routeNode->first_attribute("destination")->value());
            double magn = strtod(routeNode->first_attribute("distance")->value(), NULL);
            double mVel = strtod(routeNode->first_attribute("velocity")->value(), NULL);
            Edge *route = new Edge(magn, mVel, dest);

            ori->addEdge(route);
        }
    }
}

Node *findProvinceNode(vector<Node*>* nodeList, string name) {

    Node *node;
    for(unsigned int i = 0; i < nodeList->size(); i++){
        if(nodeList->at(i)->getProvince() == name) {
            node = nodeList->at(i);
            break;
        }
    }

    return node;
}
