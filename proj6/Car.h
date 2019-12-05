//Noah Hoffaman
//CS202

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <cstring>
#include "Vehicle.h"
using namespace std;
class Car : public Vehicle
{
private:
    //char m_plates[256];
    int m_throttle;
	virtual void serialize(ostream& os) const override;


public:
    //Default Constructor
    Car();
    
    //Paramatized Constructor
  Car(const float* lla);

    //Copy Constructor
    Car(const Car& obj);

    // Deconstructor
    virtual ~Car() override;

    //Setter
    void setThrottle(const int throttle);
    //void setPlates(const char* plates);
    //static const int getIdgen();

    //Getter
    const int getThrottle() const;
   // const char* getPlates() const;

    //other methods
    virtual void Move(const float* lla) override;
    void drive(const int throttle);
   
   void operator= (const Car &other);

};

#endif
