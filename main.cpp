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
void printShortestRoute();
void selectRoute();
Node *getSelectedNode();
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

    nodeList = new vector<Node*>();
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
                printShortestRoute();
                break;
            case 3:
                if(!validRoute())
                    break;

                outputList = NULL;
                outputList = u->getFastestPath(origin, destination);
                printShortestRoute();
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

    string ori = (origin) ? origin->getProvince() : "Ninguno";
    string dest = (destination) ? destination->getProvince() : "Ninguno";

    cout << "\n|++++++++++| Menu Principal |++++++++++|\n\n" << endl;
    cout << "Origen: "+ori+" \t Destino: "+dest+"\n\n" << endl;
    cout << "1 - Seleccion de origen y destino" << endl;
    cout << "2 - Calcular ruta mas corta" << endl;
    cout << "3 - Calcular ruta mas rapida" << endl;
    cout << "4 - Imprimir ruta actual" << endl;
    cout << "5 - Salir\n" << endl;
}

void printMenuProvinces() {

    cout << "1 - Seleccionar: San Jose" << endl;
    cout << "2 - Seleccionar: Alajuela" << endl;
    cout << "3 - Seleccionar: Heredia" << endl;
    cout << "4 - Seleccionar: Cartago" << endl;
    cout << "5 - Seleccionar: Puntarenas" << endl;
    cout << "6 - Seleccionar: Guanacaste" << endl;
    cout << "7 - Seleccionar: Limon" << endl;
    cout << "8 - Salir\n" << endl;
}

void printShortestRoute(){

    string route;

    for(unsigned int i = 0; i < outputList->size(); i++) {

        int length = outputList->at(i)->getCurrentWeight();
        string province = outputList->at(i)->getProvince();

        route = (route == "") ? route : route + " -> ";
        route =  route + province;
    }

    cout << route << endl;
}

void printFastestRoute(){

}

void selectRoute() {

    origin = NULL;
    destination = NULL;

    cout << "\n|++++++++++| Seleccione: Origen |++++++++++|\n\n" << endl;
    printMenuProvinces();
    origin = getSelectedNode();

    if(origin) {

        do {
            if(origin == destination)
                cout << "\n Destino no puede ser igual a origen \n" << endl;

            cout << "\n|++++++++++| Seleccione: Destino |++++++++++|\n\n" << endl;
            printMenuProvinces();
            destination = getSelectedNode();

        } while (origin == destination);
    }
}

bool validRoute() {

    if(!origin)
        cout << "\nOrigen: No seleccionado\n" << endl;
    if (!destination)
        cout << "\nDestino: No seleccionado\n" << endl;

    return (origin && destination) ? true : false;
}

Node *getSelectedNode() {

    Node *selected;
    bool finished;
    int input;

    while(!finished) {

        //get user input
        cin >> input;

        switch(input) {
            case 1:
                selected = findProvinceNode("San Jose");
                finished = true;
                break;
            case 2:
                selected = findProvinceNode("Alajuela");
                finished = true;
                break;
            case 3:
                selected = findProvinceNode("Heredia");
                finished = true;
                break;
            case 4:
                selected = findProvinceNode("Cartago");
                finished = true;
                break;
            case 5:
                selected = findProvinceNode("Puntarenas");
                finished = true;
                break;
            case 6:
                selected = findProvinceNode("Guanacaste");
                finished = true;
                break;
            case 7:
                selected = findProvinceNode("Limon");
                finished = true;
                break;
            case 8:
                selected = NULL;
                finished = true;
                break;
            default: break;
        }
    }

    return selected;
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
        ori->initializeEdges();

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
