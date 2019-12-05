//Noah Hoffman
//CS202

#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;

// Initializing Static Variables
int Vehicle::s_idgen = 1;
int Vehicle::s_deleted_vins[256] = {0};

// Default Constructor
Vehicle::Vehicle():
    m_vin(s_idgen)
{
    cout << "Vehicle #" << this->getVin() << ": Default-ctor" << endl;
    s_idgen++;
}

// Paramatized Constructor
Vehicle::Vehicle(const int vin, const float* lla):
    m_vin(availibleVin(vin))
{
    setLLA(lla);
    cout << "Vehicle #" << this->getVin() << ": Parametized-ctor" << endl;
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle &obj):
    m_vin(availibleVin(1))
{
    setLLA(obj.m_lla);
    cout << "Vehicle #" << this->getVin() << ": Copy-ctor" << endl;
}

// Deconstructor
Vehicle::~Vehicle()
{
    for(int i = 0; s_deleted_vins[i+1]; i++)
    {
        if (!s_deleted_vins[i])
        {
            s_deleted_vins[i] = this->getVin();
        }
    }
    
    cout << "Vehicle #" << this->getVin() << ": Dtor" << endl;
}

//setters
void Vehicle::setLLA(const float *lla)
{
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}

void Vehicle::addVin(const int vin)
{
    for(int i = 0; i < 256; i++)
    {
        if (!s_deleted_vins[i]) {
            s_deleted_vins[i] = vin;
            break;
        }
    }
}

//getters
const int Vehicle::getVin() const { return this->m_vin; }
const float *Vehicle::getLLA() const { return this->m_lla; }
const int Vehicle::getIdgen() { return s_idgen; }

//Other Methods
int Vehicle::availibleVin(const int vin)
{
    // First looks for deleted vins
    for (int i = 0; i < 256; i++)
    {
        if (s_deleted_vins[i])
        {
            int availible_vin = s_deleted_vins[i];
            s_deleted_vins[i] = 0;
            return availible_vin;
        }
    }

    // Then defers to idgen
    if (vin > s_idgen)
    {
        return vin;
    }
    else
    {
        s_idgen++;
        return s_idgen;
    }
}

ostream & operator<< (ostream & os, const Vehicle & vehicle)
{
    os << "Vehicle #"
    << vehicle.m_vin << " @ ["
    << vehicle.m_lla[0] << ", "
    << vehicle.m_lla[1] << ", "
    << vehicle.m_lla[2] << ']';

    return os;
}

Vehicle& Vehicle::operator= (const Vehicle &other)
{
cout << "Vehicle #" << this->getVin() << ": Assignment" << endl;    
this->setLLA(other.getLLA());
return *this;
}

void Vehicle::move(const float* lla)
{
    cout << "Vehicle #" << this->getVin() << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}
