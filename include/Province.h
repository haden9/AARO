#ifndef PROVINCE_H
#define PROVINCE_H

class Province
{
    public:
        Province(std::string name);
        virtual ~Province();
        std::string getName();
    protected:
    private:
        std::string name;

};

#endif // PROVINCE_H
