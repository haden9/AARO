#include <iostream>
#include <fstream>
#include <vector>
#include <rapidxml_utils.hpp>

#include "Node.h"
#include "Edge.h"
#include "Utils.h"

using namespace rapidxml;
using namespace std;

int main()
{
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

    // Creating a vector that will hold all the province nodes
    vector<Node*> nodeList;

    // Iterating over the provinces
    for(xml_node<> * provinceNode = rootNode->first_node("province"); provinceNode; provinceNode = provinceNode->next_sibling())
    {
        Node *prov = new Node(provinceNode->first_attribute("name")->value());

        // Iterating over the routes
        for(xml_node<> * routeNode = provinceNode->first_node("route"); routeNode; routeNode = routeNode->next_sibling())
        {
            Node *dest = new Node(routeNode->first_attribute("destination")->value());
            double magn = strtod(routeNode->first_attribute("distance")->value(), NULL);
            double mVel = strtod(routeNode->first_attribute("velocity")->value(), NULL);
            Edge *rout = new Edge(magn, mVel, dest);

            prov->addEdge(rout);
        }

        nodeList.push_back(prov);
    }

    Utils *u = new Utils(nodeList);

    //u->getShortestPath(nodeList.at(1), nodeList.at(2));

    return 0;
}
