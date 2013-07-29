#include <iostream>
#include <fstream>
#include <vector>
#include <rapidxml_utils.hpp>

#include "Node.h"
#include "Edge.h"
#include "Utils.h"

using namespace rapidxml;
using namespace std;

void printMenu();
void printMenuProvinces();
void selectRoute();
void setSelectedNode(Node *node);
bool validRoute();

void readXML();
void createProvinces(xml_node<> *rootNode);
void addEdgesToProvinces(xml_node<> *rootNode);
Node *findProvinceNode(string name);

vector<Node*> *nodeList, *outputList;
Node *origin, *destination;

int main()
{
    bool finished;
    int input;

    nodeList = (vector<Node*>*)malloc(sizeof(nodeList));
    readXML();
    Utils *u = new Utils(nodeList);

    while(!finished){

        printMenu();

        //get user input
        cin >> input;

        switch(input){
            case 1:
                selectRoute();
                break;
            case 2:
                if(!validRoute())
                    break;

                outputList = NULL;
                outputList = u->getShortestPath(origin, destination);

                break;
            case 3:
                if(!validRoute())
                    break;

                outputList = NULL;
                outputList = u->getFastestPath(origin, destination);
                break;
            case 4:
                //print route
                finished = true;
                break;
            case 5:
                finished = true;
                break;
            default: break;
        }
    }

    return 0;
}

void printMenu() {

    cout << "|*******|Menu Principal|*******|\n\n" << endl;
    cout << "1 - Seleccion de origen y destino\n" << endl;
    cout << "2 - Calcular ruta mas corta\n" << endl;
    cout << "3 - Calcular ruta mas rapida\n" << endl;
    cout << "4 - Imprimir ruta actual\n" << endl;
    cout << "5 - Salir\n" << endl;
}

void printMenuProvinces() {

    cout << "1 - Seleccionar: San Jose\n" << endl;
    cout << "2 - Seleccionar: Alajuela\n" << endl;
    cout << "3 - Seleccionar: Heredia\n" << endl;
    cout << "4 - Seleccionar: Cartago\n" << endl;
    cout << "5 - Seleccionar: Puntarenas\n" << endl;
    cout << "6 - Seleccionar: Guanacaste\n" << endl;
    cout << "7 - Seleccionar: Limon\n" << endl;
    cout << "8 - Salir\n" << endl;
}

void selectRoute() {

    origin = NULL;
    destination = NULL;

    cout << "|*******| Seleccione: Origen |*******|\n\n" << endl;
    printMenuProvinces();
    setSelectedNode(origin);

    if(origin) {

        cout << "|*******| Seleccione: Destino |*******|\n\n" << endl;
        printMenuProvinces();
        setSelectedNode(destination);
    }
}

bool validRoute() {

    if(!origin)
        cout << "Origen: No seleccionado\n" << endl;
    else if (!destination)
        cout << "Destino: No seleccionado\n" << endl;

    return (origin && destination) ? true : false;
}

void setSelectedNode(Node *node) {

    bool finished;
    int input;

    while(!finished) {

        //get user input
        cin >> input;

        switch(input) {
            case 1:
                node = findProvinceNode("San Jose");
                finished = true;
                break;
            case 2:
                node = findProvinceNode("Alajuela");
                finished = true;
                break;
            case 3:
                node = findProvinceNode("Heredia");
                finished = true;
                break;
            case 4:
                node = findProvinceNode("Cartago");
                finished = true;
                break;
            case 5:
                node = findProvinceNode("Puntarenas");
                finished = true;
                break;
            case 6:
                node = findProvinceNode("Guanacaste");
                finished = true;
                break;
            case 7:
                node = findProvinceNode("Limon");
                finished = true;
                break;
            case 8:
                finished = true;
                break;
            default: break;
        }
    }
}

void readXML(){

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

    createProvinces(rootNode);
    addEdgesToProvinces(rootNode);
}

void createProvinces(xml_node<> *rootNode){
    // Iterating over the provinces
    for(xml_node<> * provinceNode = rootNode->first_node("province"); provinceNode; provinceNode = provinceNode->next_sibling())
    {
        Node *prov = new Node(provinceNode->first_attribute("name")->value());
        //adds the province node to the nodeList
        nodeList->push_back(prov);
    }
}


void addEdgesToProvinces(xml_node<> *rootNode){

    for(xml_node<> * provinceNode = rootNode->first_node("province"); provinceNode; provinceNode = provinceNode->next_sibling())
    {
        Node *ori = findProvinceNode(provinceNode->first_attribute("name")->value());

        // Iterating over the routes
        for(xml_node<> * routeNode = provinceNode->first_node("route"); routeNode; routeNode = routeNode->next_sibling()) {

            Node *dest = findProvinceNode(routeNode->first_attribute("destination")->value());
            double magn = strtod(routeNode->first_attribute("distance")->value(), NULL);
            double mVel = strtod(routeNode->first_attribute("velocity")->value(), NULL);
            Edge *route = new Edge(magn, mVel, dest);

            ori->addEdge(route);
        }
    }
}

Node *findProvinceNode(string name) {

    Node *node;
    for(unsigned int i = 0; i < nodeList->size(); i++){
        if(nodeList->at(i)->getProvince() == name) {
            node = nodeList->at(i);
            break;
        }
    }

    return node;
}
