//Noah Hoffman
//CS202

#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;



// Default Constructor
Vehicle::Vehicle()
{
   cout << "Vehicle: Default-ctor" << endl;
}

// Paramatized Constructor
Vehicle::Vehicle(const float* lla)
{
    this->SetLLA(lla);
    cout << "Vehicle: Parametrized-ctor" << endl;
}

// Copy Constructor
Vehicle::Vehicle(const Vehicle& obj)
{
    this->SetLLA(obj.getLLA());
    cout << "Vehicle: Copy-ctor" << endl;
}

// Deconstructor
Vehicle::~Vehicle()
{
    cout << "Vehicle: Dtor" << endl;
}

//setters
void Vehicle::SetLLA(const float *lla)
{
    m_lla[0] = lla[0];
    m_lla[1] = lla[1];
    m_lla[2] = lla[2];
}



//getters

const float *Vehicle::getLLA() const { return this->m_lla; }


//Other Methods

ostream & operator<< (ostream & os, const Vehicle & vehicle)
{
  
    vehicle.serialize(os);
    return os;
}

void Vehicle::operator= (const Vehicle &other)
{
    this->SetLLA(other.getLLA());
    cout << "Vehicle: Assignment" << endl;
}

void Vehicle::serialize(ostream& os) const
{
    const float *ptr = this->getLLA();
    os << "Vehicle @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}
