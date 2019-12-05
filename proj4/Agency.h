#ifndef AGENCY_H
#define AGENCY_H

#include "Car.h"

class Agency
{
public:
    //Default Constructor
    Agency();

    Agency(char* name, int zipcode, Car* inventory);

    //Setter
    void setName(char* name);
    void setZip(int zipcode);
    void setInventory(Car* inventory);

    //Getter
    char* getName();
    int getZip();
    Car* getInventory();

    //Overload Operator
    Car& operator[] (const int index);
    void printData();
    void readData(std::ifstream & infile);

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
};

#endif
