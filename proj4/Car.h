#include "Sensors.h"

#ifndef CAR_H
#define CAR_H

class Car
{

    
public:
    // Default Constructor
    Car();

    // Paramatized Constructor
    Car(int year, char *make, char *model, float price, bool available);

    // Copy Constructor
    Car(const Car & other);

    // Setters
    void setYear(int year);
    void setMake(const char *make);
    void setModel(const char *model);
    void setSensors(Sensor *sensors);
    void setBaseprice(float baseprice);
    void setAvailability(bool available);
    void setOwner(char* owner);

    // Getter
    int     getYear();
    char*   getMake();
    char*   getModel();
    Sensor* getSensors();
    float   getBaseprice();
    float   getFinalprice();
    bool    getAvailability();
    char*   getOwner();

    // Other methods
    void addLessee();
    void operator+ (char *type);
    float estimateCost(const int num_of_days);
    void print();
    void updatePrice(); // updates final price

private:
    // Member Variables
    int    m_year;
    char   m_make[256];
    char   m_model[256];
    Sensor m_sensors[3];
    float  m_baseprice;
    float  m_finalprice;
    bool   m_available;
    char   m_owner[256];
};

#endif
