#include <iostream>
#include <rapidxml_utils.hpp>

#include "Province.h"
#include "Node.h"

using std::cout;

int main()
{
    Province *p = new Province("San Jose");
    Node *n = new Node(p);

    rapidxml::file<> xmlFile("xml/pais.xml");
    cout << xmlFile.data();
    return 0;
}
