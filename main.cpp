#include <iostream>
#include <Nodo.h>
#include <rapidxml_utils.hpp>

using namespace std;

int main()
{
    rapidxml::file<> xmlFile("xml/pais.xml");
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    cout << doc.first_node()->last_node()->first_node()->value();
    return 0;
}
