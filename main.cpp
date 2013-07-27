#include <iostream>
#include <rapidxml_utils.hpp>

#include "Node.h"

using std::cout;

int main()
{
    Node *n = new Node("San Jose");

    rapidxml::file<> xmlFile("xml/pais.xml");
    cout << xmlFile.data();
    return 0;
}
