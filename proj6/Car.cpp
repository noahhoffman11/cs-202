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
    cout << "Car: Default-ctor" << endl;
}

//Paramatized constructor
Car::Car(const float* lla):
    Vehicle(lla)
{
    cout << "Car: Parametized-ctor" << endl;
}

//Copy constructor
Car::Car(const Car &obj):
    Vehicle(obj)
{
    
    cout << "Car : Copy-ctor" << endl;
this->setThrottle(0);
}

//Deconstructor
Car::~Car()
{
    cout << "Car: Dtor" << endl;
}

// Setters
void Car::setThrottle(const int throttle)
{
    m_throttle = throttle;
}


//getters
const int Car::getThrottle() const { return m_throttle; }


// Other Methods
void Car::Move(const float* lla)
{
    
    cout << "Car: DRIVE to destination, with throttle @ 75 " <<endl;

    this->drive( 75 );
    this->SetLLA( lla );
}

void Car::drive(const int throttle)
{
    this->setThrottle(throttle);
}


void Car::operator=(const Car &other)
{
    cout << "Car: Assignment" << endl;
    this->SetLLA(other.getLLA());
    this->setThrottle(other.getThrottle());
}

void Car::serialize(ostream& os) const
{
    const float *ptr = this->getLLA();
    cout << "Car: Throttle: " << this->getThrottle()
    << " @ [" << *ptr << ", ";
    ptr++;
    os << *ptr << ", ";
    ptr++;
    os << *ptr << ']';
}

