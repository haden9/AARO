#include "Province.h"

Province::Province(string name)
    : name(name)
{
    //ctor
}

Province::~Province()
{
    //dtor
}

string Province::getName() {
    return name;
}
