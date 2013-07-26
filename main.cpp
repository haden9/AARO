#include <iostream>
#include <rapidxml_utils.hpp>

#include "Nodo.h"

using namespace std;

int main()
{
    rapidxml::file<> xmlFile("xml/pais.xml");
    cout << xmlFile.data();
    return 0;
}
