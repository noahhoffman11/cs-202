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
        const int m_vin;

    private:
        static int s_idgen;
        static int s_deleted_vins[256];


    public:

    //Regular CTOR
    Vehicle();


    //Parameterized CTOR
    Vehicle(const int m_vin, const float* m_lla);

    //copy constructor
    Vehicle(const Vehicle &obj);

    //deconstructor
    ~Vehicle();

    // Setters
    void setLLA(const float *lla);
    void addVin(const int vin);

    // Getters
    const int getVin() const;
    const float *getLLA() const;
    static const int getIdgen();

    // Other Methods
    static int availibleVin(const int vin);
    friend ostream & operator<<(ostream & os, const Vehicle & vehicle);
    Vehicle& operator= (const Vehicle &other);
    void move(const float *lla);

};

#endif
