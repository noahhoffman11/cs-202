#include "RentalCar.h"

void myStringCopy(char* destination, char* source){ //why would I use this function also???!!!
    int i = 0;

    while(source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0'; // add '\0' at the end
}

RentalCar::RentalCar(){
    RentalCar::setYear(0000);
    RentalCar::setMake("EMPTY");
    RentalCar::setModel("EMPTY");
    RentalCar::setPrice(0.00);
    RentalCar::setAvailability(0);
}

RentalCar::RentalCar(int year, char *make, char *model, float price, bool available){
    RentalCar::setYear(year);
    RentalCar::setMake(make);
    RentalCar::setModel(model);
    RentalCar::setPrice(price);
    RentalCar::setAvailability(available);
}

//Trend setters... ;)
void RentalCar::setYear(int year){
    m_year = year;
}

void RentalCar::setMake(char *make){
    myStringCopy(m_make, make);
}


void RentalCar::setModel(char *model){
    myStringCopy(m_model, model);
}

void RentalCar::setPrice(float price){
    m_price = price;
}

void RentalCar::setAvailability(bool available){
    m_available = available;
}

// Go Getters... See what I did there ;)
int RentalCar::getYear(){
    return m_year;
}

char* RentalCar::getMake(){
    return m_make;
}

char* RentalCar::getModel(){
    return m_model;
}

float RentalCar::getPrice(){
    return m_price;
}

bool RentalCar::getAvailability(){
    return m_available;
}

float RentalCar::estimateCost(const int num_of_days){
    return m_price * num_of_days;
}