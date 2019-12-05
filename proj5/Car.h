//Noah Hoffaman
//CS202

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;
class Car : Vehicle
{
private:
    char m_plates[256];
    int m_throttle;


public:
    //Default Constructor
    Car();
    
    //Paramatized Constructor
    Car(const char* plates, const int vin, const float* lla);

    //Copy Constructor
    Car(const Car& obj);

    // Deconstructor
    ~Car();

    //Setter
    void setThrottle(const int throttle);
    void setPlates(const char* plates);
    static const int getIdgen();

    //Getter
    const int getThrottle() const;
    const char* getPlates() const;

    //other methods
    void move(const float* lla);
    void drive(const int throttle);
    friend ostream & operator<<(ostream & os, const Car & car);
    Car& operator= (const Car &other);

};

#endif
