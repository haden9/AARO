#ifndef PROVINCE_H
#define PROVINCE_H

#include <string>

using namespace std;

class Province
{
    public:
        Province(string name);
        virtual ~Province();
        string getName();
    protected:
    private:
        string name;

};

#endif // PROVINCE_H
