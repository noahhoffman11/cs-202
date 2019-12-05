//Noah Hoffman
//CS202

#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"
using namespace std;


//Default constructor
Car::Car():
    m_throttle(0)

{
    cout << "Car #" << this->getVin() << ": Default-ctor" << endl;
this->setPlates("EMPTY");
}

//Paramatized constructor
Car::Car(const char* plates, const int vin, const float* lla):
    Vehicle(vin, lla)

{
    this->setPlates(plates);
    cout << "Car #" << this->getVin() << ": Parametized-ctor" << endl;
this->setThrottle(0);
     
}

//Copy constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{
    setPlates(obj.getPlates());
    cout << "Car #" << this->getVin() << ": Copy-ctor" << endl;
this->setThrottle(0);
}

//Deconstructor
Car::~Car()
{
    cout << "Car #" << this->getVin() << ": Dtor" << endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}

void Car::setPlates(const char* plates)
{
    strcpy(m_plates, plates); // copy the strings
}

//getters
const int Car::getThrottle() const { return m_throttle; }
const char* Car::getPlates() const { return m_plates; }
const int Car::getIdgen() { return Vehicle::getIdgen(); }

// Other Methods
void Car::move(const float* lla)
{
    cout << "Car #" << this->getVin()
    << ": DRIVE to destination, with throttle @ 75 "
    << endl;

    this->drive( 75 );
    this->setLLA( lla );
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}

ostream & operator<< (ostream & os, const Car & car)
{
    const float *lla = car.getLLA();
    
    os << "Car #"
    << car.getVin() << " Plates: "
    << car.getPlates() << ", Throttle: "
    << car.getThrottle() << " @ ["
    << *lla << ", ";
    ++lla;
    os << *lla << ", ";
    ++lla;
    os << *lla << ']';

    return os;
}

Car& Car::operator= (const Car &other)
{
this->setLLA(other.getLLA());
this->setPlates(other.getPlates());

cout << "Car #" << this->getVin() << ": Assignment" << endl; 
   

return *this;
}

