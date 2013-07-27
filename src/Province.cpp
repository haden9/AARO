
#include <string>
#include "Province.h"

Province::Province(std::string name)
    : name(name)
{
    //ctor
}

Province::~Province()
{
    //dtor
}

std::string Province::getName() {
    return name;
}
