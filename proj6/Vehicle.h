//Noah Hoffman
//CS202

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <cstring>
using namespace std;
class Vehicle
{
    protected:
        float m_lla[3];
      

    private:
           virtual void serialize(ostream & os) const;


    public:

    //Regular CTOR
    Vehicle();


    //Parameterized CTOR
      Vehicle(const float* m_lla);

    //copy constructor
    Vehicle(const Vehicle &obj);

    //deconstructor
        virtual ~Vehicle();

    // Setters
    void SetLLA(const float *lla);
   

    // Getters
   
    const float *getLLA() const;
   

    // Other Methods
   virtual void Move(const float* lla)=0;
    friend ostream & operator<<(ostream & os, const Vehicle & vehicle);
    void operator= (const Vehicle &other);
   

};

#endif
