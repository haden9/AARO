#include <iostream>
#include <Nodo.h>
#include <rapidxml_utils.hpp>

using namespace std;

int main()
{
    rapidxml::file<> xmlFile("xml/pais.xml");
    cout << xmlFile.data();
    return 0;
}
